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
  private var index = 0
  
  var count: Int { elements.count - index }
  var isEmpty: Bool { count == 0 }
  
  mutating func enqueue(_ element: T) {
    elements.append(element)
  }
  
  mutating func dequeue() -> T? {
    guard !isEmpty else { return nil }
    defer { index += 1 }
    return elements[index]
  }
}

private let fileIO = FileIO()

func solution() {
  let testCase = fileIO.readInt()
  var answer = ""
  
  for _ in 0..<testCase {
    let (buildingCount, ruleCount) = readPairInteger()
    let buildTimes = readIntegers(buildingCount)
    let buildMap = configureBuildMap(buildingCount: buildingCount, ruleCount: ruleCount)
    let destination = fileIO.readInt()
    let time = totalBuildingTime(
      buildTimes: buildTimes,
      buildMap: buildMap,
      destination: destination
    )
    answer += "\(time)\n"
  }
  
  print(answer)
}

func totalBuildingTime(buildTimes: [Int], buildMap : [[Int]], destination: Int) -> Int {
  var totalBuildTimes = Array(repeating: 0, count: buildMap.count)
  var indegrees = configureIndegrees(buildMap: buildMap)
  var queue = Queue<Int>()
  
  
  indegrees.enumerated().filter { $0.element == 0 }
    .forEach {
      queue.enqueue($0.offset)
      totalBuildTimes[$0.offset] = buildTimes[$0.offset]
    }
  
  while let current = queue.dequeue() {
    for next in buildMap[current] {
      indegrees[next] -= 1
      if indegrees[next] == 0 { queue.enqueue(next) }
      totalBuildTimes[next] = max(totalBuildTimes[next], totalBuildTimes[current] + buildTimes[next])
    }
  }
  
  return totalBuildTimes[destination - 1]
}

func configureBuildMap(buildingCount: Int, ruleCount: Int) -> [[Int]] {
  var buildMap = Array(repeating: [Int](), count: buildingCount)
  
  for _ in 0..<ruleCount {
    let (from, to) = readPairInteger()
    buildMap[from - 1].append(to - 1)
  }
  
  return buildMap
}

func configureIndegrees(buildMap: [[Int]]) -> [Int] {
  var indegrees = Array(repeating: 0, count: buildMap.count)
  
  for i in 0..<buildMap.count {
    for j in buildMap[i] {
      indegrees[j] += 1
    }
  }
  
  return indegrees
}

func readPairInteger() -> (Int, Int) {
  let input1 = fileIO.readInt()
  let input2 = fileIO.readInt()
  return (input1, input2)
}

func readIntegers(_ n: Int) -> [Int] {
  var inputs = [Int]()
  for _ in 0..<n { inputs.append(fileIO.readInt()) }
  return inputs
}

solution()
