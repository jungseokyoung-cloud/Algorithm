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

// MARK: - Heap
struct Heap<T: Comparable> {
  enum HeapType {
    case max
    case min
  }

  private(set) var elements: [T] = []
  private let compare: (T, T) -> Bool

  let type: HeapType
  var top: T? { elements.first }
  var isEmpty: Bool { elements.isEmpty }
  var count: Int { elements.count }

  init(type: HeapType) {
    self.type = type

    switch type {
      case .max:
        self.compare = { $0 > $1 }
      case .min:
        self.compare = { $0 < $1 }
    }
  }
}

// MARK: - Heap Methods
extension Heap {
  mutating func push(_ element: T) {
    elements.append(element)
    shiftUp(index: count - 1)
  }

  @discardableResult
  mutating func pop() -> T? {
    guard !isEmpty else { return nil }

    let element = elements.first

    elements.swapAt(0, count - 1)
    elements.removeLast()
    shiftDown()

    return element
  }
}

// MARK: - Heap Private Methods
private extension Heap {
  mutating func shiftUp(index: Int) {
    var current = index
    var parent = parentIndex(for: current)

    while current > 0 && compare(elements[current], elements[parent]) {
      elements.swapAt(current, parent)

      current = parent
      parent = parentIndex(for: current)
    }
  }

  mutating func shiftDown() {
    var current = 0

    while true {
      let (left, right) = childIndexs(for: current)
      var candidate = current

      if left < count && compare(elements[left], elements[current]) {
        candidate = left
      }

      if right < count && compare(elements[right], elements[current]) && compare(elements[right], elements[left]) {
        candidate = right
      }

      if candidate == current { break }

      elements.swapAt(current, candidate)
      current = candidate
    }
  }

  func parentIndex(for index: Int) -> Int {
    return (index - 1) / 2
  }

  func childIndexs(for index: Int) -> (leftChild: Int, rightChild: Int) {
    let leftIndex = leftChildIndex(for: index)
    let rightIndex = rightChildIndex(for: index)
    return (leftChild: leftIndex, rightChild: rightIndex)
  }

  func leftChildIndex(for index: Int) -> Int {
    return 2 * index + 1
  }

  func rightChildIndex(for index: Int) -> Int {
    return 2 * index + 2
  }
}

struct Problem: Comparable {
  let deadLine: Int
  let score: Int
  
  static func < (lhs: Problem, rhs: Problem) -> Bool {
    return lhs.deadLine == rhs.deadLine ? lhs.score > rhs.score : lhs.deadLine < rhs.deadLine
  }
}

fileprivate let fileIO = FileIO()

func solution() {
  let n = readInteger()
  let problems = configureProblems(n)
  let result = maxScore(for: problems)
  print(result)
}

func readInteger() -> Int {
  return fileIO.readInt()
}

func configureProblems(_ n: Int) -> [Problem] {
  var problems = [Problem]()
  
  (0..<n).forEach { _ in
    let num1 = fileIO.readInt()
    let num2 = fileIO.readInt()
    
    problems.append(.init(deadLine: num1, score: num2))
  }
  
  return problems
}

func maxScore(for problems: [Problem]) -> Int {
  var heap = Heap<Int>(type: .min)
  var result = 0
  var currentTime = 0
  let sortedProblem = problems.sorted(by: <)
  
  for problem in sortedProblem {
    guard currentTime >= problem.deadLine else {
      heap.push(problem.score)
      result += problem.score
      currentTime += 1
      continue
    }
    
    guard let top = heap.top, top < problem.score else { continue }
    heap.pop()
    result += (problem.score - top)
    heap.push(problem.score)
  }
  
  return result
}

solution()
