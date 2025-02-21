// MARK: - Heap
struct Heap<T: Comparable> {
  enum HeapType {
    case max
    case min
  }
  
  private var elements: [T] = []
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

struct HeapElement: Comparable {
  static func < (lhs: HeapElement, rhs: HeapElement) -> Bool {
    return lhs.value < rhs.value
  }
  
  let value: Int
  let classNum: Int
  let index: Int
  
  init(_ value: Int, _ classNum: Int, _ index: Int) {
    self.value = value
    self.classNum = classNum
    self.index = index
  }
}

func solution() {
  let (n, _) = readPairInterger()
  let powers = configurePower(n)
  let result = getResult(powers)
  print(result)
}

func configurePower(_ n: Int) -> [[Int]] {
  var results: [[Int]] = []
  
  for _ in 0..<n {
    results.append(readIntegers())
  }
  
  return results
}

func readPairInterger() -> (Int, Int) {
  let inputs = readIntegers()
  
  return (inputs[0], inputs[1])
}

func readIntegers() -> [Int] {
  return readLine()!.split(separator: " ").map { Int($0)! }
}

func getResult(_ powers: [[Int]]) -> Int {
  let sortedPowers = powers.map { $0.sorted(by: <) }
  var heap = Heap<HeapElement>(type: .min)
  
  var result = Int.max
  var currentMax = 0
  
  for index in 0..<sortedPowers.count {
    let value = sortedPowers[index][0]
    currentMax = max(currentMax, value)
    heap.push(.init(value, index, 0))
  }
  
  while let element = heap.pop() {
    result = min(result, currentMax - element.value)

    guard element.index + 1 != powers[0].count else { break }
    let nextValue = sortedPowers[element.classNum][element.index + 1]
    currentMax = max(currentMax, nextValue)
    heap.push(.init(nextValue, element.classNum, element.index + 1))
  }
  
  return result
}

solution()
