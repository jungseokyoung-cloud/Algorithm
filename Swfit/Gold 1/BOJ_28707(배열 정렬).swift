struct Operator {
  let index1: Int
  let index2: Int
  let cost: Int
  
  init(_ index1: Int, _ index2: Int, _ cost: Int) {
    self.index1 = index1
    self.index2 = index2
    self.cost = cost
  }
}

struct HeapItem: Comparable {
  static func < (lhs: HeapItem, rhs: HeapItem) -> Bool {
    return lhs.cost < rhs.cost
  }
  
  let current: String
  let cost: Int
  init(_ current: String, _ cost: Int) {
    self.current = current
    self.cost = cost
  }
}

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

func solution() {
  let _ = readInteger()
  let numbers = readIntegers()
  let m = readInteger()
  let operators = configureOperators(m)
  let result = minCost(target: numbers, operators: operators)
  print(result)
}

func configureOperators(_ m: Int) -> [Operator] {
  var operators: [Operator] = []
  
  for _ in 0..<m {
    let input = readTupleIntegers()
    operators.append(.init(input.0 - 1, input.1 - 1, input.2))
  }
  
  return operators
}

func readInteger() -> Int {
  return Int(readLine()!)!
}

func readTupleIntegers() -> (Int, Int, Int) {
  let inputs = readIntegers()
  
  return (inputs[0], inputs[1], inputs[2])
}

func readIntegers() -> [Int] {
  return readLine()!.split(separator: " ").compactMap { Int($0) }
}

func minCost(target numbers: [Int], operators: [Operator]) -> Int {
  var isVis = [String: Int]()
  var heap = Heap<HeapItem>(type: .min)
  
  let st = numbers.toString()
  let en = numbers.sorted().toString()

  heap.push(.init(st, 0))
  isVis[st] = 0
  
  while let top = heap.pop() {
    let current = top.current.toArray()

    guard let cost = isVis[top.current], cost <= top.cost else {
      continue
    }

    for opt in operators {
      var temp = current
      let tempCost = top.cost + opt.cost
      temp.swapAt(opt.index1, opt.index2)
      let tempString = temp.toString()
      
      if let cost = isVis[tempString], cost <= tempCost {
        continue
      }
      
      isVis[tempString] = tempCost
      heap.push(.init(tempString, tempCost))
    }
  }
  
  return isVis[en] ?? -1
}

extension Array where Element == Int {
  func toString() -> String {
    return self.map { "\($0)" }.joined(separator: "")
  }
}

extension String {
  subscript(idx: Int) -> String? {
    guard(0..<count).contains(idx) else {
      return nil
    }
    let target = index(startIndex, offsetBy: idx)
    return String(self[target])
  }
  
  func toArray() -> [Int] {
    var index = 0
    var results = [Int]()
    
    while index < self.count {
      defer { index += 1 }
      if self[index] == "0" {
        results.removeLast()
        results.append(10)
        continue
      }
      
      results.append(Int(self[index]!)!)
    }
    
    return results
  }
}

solution()
