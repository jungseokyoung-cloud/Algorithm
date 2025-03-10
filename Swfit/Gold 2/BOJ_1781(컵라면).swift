//
//  BOJ_1781(컵라면).swift
//  BOJ
//
//  Created by jung on 1/6/25.
//

struct Heap<T: Comparable> {
  enum HeapType {
    case min
    case max
  }
  private var elements = [T]()
  private var compare: (T, T) -> Bool
  
  let type: HeapType
  
  var isEmpty: Bool { elements.isEmpty }
  var count: Int { elements.count }
  var peek: T? { elements.first }
  
  init(type: HeapType) {
    self.type = type
    
    switch type {
      case .min:
        self.compare = { $0 < $1 }
      case .max:
        self.compare = { $0 > $1 }
    }
  }
}

// MARK: - Heap Methods
extension Heap {
  mutating func push(_ element: T) {
    elements.append(element)
    shiftUp(lastIndex: elements.count - 1)
  }
  
  mutating func pop() -> T? {
    guard !isEmpty else { return nil }
    
    defer {
      elements.swapAt(0, elements.count - 1)
      elements.removeLast()
      shiftDown()
    }
    
    return elements[0]
  }
}

// MARK: - Private Heap Methods
private extension Heap {
  mutating func shiftUp(lastIndex: Int) {
    var current = lastIndex
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
      let (leftChild, rightChild) = childIndexs(for: current)
      var candidate = current
      
      if
        leftChild < count,
        compare(elements[leftChild], elements[candidate]) {
        candidate = leftChild
      }
      
      if
        rightChild < count,
        compare(elements[rightChild], elements[candidate]),
        compare(elements[rightChild], elements[leftChild]) {
        candidate = rightChild
      }
      
      guard candidate != current else { break }
      elements.swapAt(candidate, current)
      current = candidate
    }
  }
  
  
  func parentIndex(for index: Int) -> Int {
    return (index - 1) / 2
  }
  
  func childIndexs(for index: Int) -> (leftChild: Int, rightChild: Int) {
    return (2 * index + 1, 2 * index + 2)
  }
}

struct PriorityQueue<T: Comparable> {
  private var heap: Heap<T>
  
  var isEmpty: Bool { heap.isEmpty }
  var count: Int { heap.count }
  var front: T? { heap.peek }
  
  init(type: Heap<T>.HeapType) {
    self.heap = Heap(type: type)
  }
  
  mutating func enqueue(_ element: T) {
    heap.push(element)
  }
  
  @discardableResult
  mutating func dequeue() -> T? {
    return heap.pop()
  }
}

func solution() {
  let n = readInt()
  var problems = [Problem]()
  
  (0..<n).forEach { _ in
    let (deadLine, score) = readPairIntegers()
    problems.append(.init(deadLine, score))
  }
  problems.sort {
    ($0.deadLine == $1.deadLine) ? $0.score > $1.score : $0.deadLine < $1.deadLine
  }

  let result = maxScore(problems: problems)
  print(result)
}

func maxScore(problems: [Problem]) -> Int {
  var queue = PriorityQueue<Problem>(type: .min)
  var result = 0
  
  problems.forEach { problem in
    if queue.count < problem.deadLine {
      queue.enqueue(problem)
    } else if let front = queue.front, front.score < problem.score, queue.count == problem.deadLine {
      queue.dequeue()
      queue.enqueue(problem)
    }
  }
  
  while let front = queue.dequeue() {
    result += front.score
  }
  return result
}

func readInt() -> Int {
  return Int(readLine()!)!
}

func readPairIntegers() -> (Int, Int) {
  let inputs = readLine()!.split(separator: " ").map { Int($0)! }
  
  return (inputs[0], inputs[1])
}

solution()
