import Foundation

class FileIO {
  @inline(__always) private var buffer: [UInt8] = Array(FileHandle.standardInput.readDataToEndOfFile()) + [0], byteIdx = 0
  
  @inline(__always) private func readByte() -> UInt8 {
    defer { byteIdx += 1 }
    return buffer.withUnsafeBufferPointer { $0[byteIdx] }
  }
  
  @inline(__always) func readInt() -> Int {
    var number = 0, byte = readByte(), isNegative = false
    while byte == 10 || byte == 32 { byte = readByte() }
    if byte == 45 { byte = readByte(); isNegative = true }
    while 48...57 ~= byte { number = number * 10 + Int(byte - 48); byte = readByte() }
    return number * (isNegative ? -1 : 1)
  }
  
  @inline(__always) func readStirngSum() -> Int {
    var byte = readByte()
    while byte == 10 || byte == 32 { byte = readByte() }
    var sum = Int(byte)
    while byte != 10 && byte != 32 && byte != 0 { byte = readByte(); sum += Int(byte) }
    return sum - Int(byte)
  }
  
  @inline(__always) private func write(_ output: String) {
    FileHandle.standardOutput.write(output.data(using: .utf8)!)
  }
}

struct Queue<T> {
  private var elements = [T]()
  private var head = 0
  
  var count: Int { elements.count - head }
  var isEmpty: Bool { count == 0 }
  var front: T? {
    guard !isEmpty else { return nil }
    return elements[head]
  }
  
  mutating func enqueue(_ element: T) {
    elements.append(element)
  }
  
  @discardableResult
  mutating func dequeue() -> T? {
    guard !isEmpty else { return nil }
    defer { head += 1 }
    return elements[head]
  }
}

struct Point {
  let x: Int
  let y: Int
  
  init(_ x: Int, _ y: Int) {
    self.x = x
    self.y = y
  }
}

fileprivate let fileIO = FileIO()
fileprivate let dx = [-1, 1, 0, 0]
fileprivate let dy = [0, 0, -1, 1]
fileprivate var n: Int = 0
fileprivate var m: Int = 0
fileprivate var emptyCount: Int = 0
fileprivate var virusPoints = [Point]()
fileprivate var selectedVirusPoints = [Point]()
fileprivate var map = [[Int]]()
fileprivate var result = Int.max

func solution() {
  n = fileIO.readInt()
  m = fileIO.readInt()
  configureMap(n)
  minVirousSpreadCount(index: 0)
  result = result == Int.max ? -1 : result
  print(result)
}

func configureMap(_ n: Int) {
  map = Array(repeating: Array(repeating: 0, count: n), count: n)
  
  for i in 0..<n {
    for j in 0..<n {
      map[i][j] = fileIO.readInt()
      
      if map[i][j] == 0 {
        emptyCount += 1
      } else if map[i][j] == 2 {
        virusPoints.append(Point(i, j))
      }
    }
  }
}

func minVirousSpreadCount(index: Int) {
  if selectedVirusPoints.count == m {
    result = min(spreadVirus(), result)
    return
  }
  
  guard index < virusPoints.count else { return }
  
  selectedVirusPoints.append(virusPoints[index])
  minVirousSpreadCount(index: index + 1)
  selectedVirusPoints.removeLast()
  minVirousSpreadCount(index: index + 1)
}

func spreadVirus() -> Int {
  var maxSpreadCount = 0
  var spreadCount = 0
  
  var isVis = Array(repeating: Array(repeating: -1, count: n), count: n)
  var queue = Queue<Point>()
  selectedVirusPoints.forEach {
    queue.enqueue($0)
    isVis[$0.x][$0.y] = 0
  }
  
  while let top = queue.dequeue() {
    let count = isVis[top.x][top.y]
    if map[top.x][top.y] == 0 { spreadCount += 1 }
    maxSpreadCount = max(maxSpreadCount, count)
    if emptyCount == spreadCount { break }
    
    for dis in 0..<4 {
      let nextX = top.x + dx[dis]
      let nextY = top.y + dy[dis]
      
      guard nextX >= 0, nextX < n, nextY >= 0, nextY < n else { continue }
      guard isVis[nextX][nextY] == -1, map[nextX][nextY] != 1 else { continue }

      isVis[nextX][nextY] = count + 1
      
      queue.enqueue(.init(nextX, nextY))
    }
  }

  return spreadCount == emptyCount ? maxSpreadCount : Int.max
}

solution()
