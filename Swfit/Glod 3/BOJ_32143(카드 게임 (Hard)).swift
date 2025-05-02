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

func solution() {
  let hp = readInteger()
  let (_, count) = readPairIntegers()
  let initalCards = readIntegers()
  let extraCards = readExtraCards(count: count)
  
  let results = playGame(hp: hp, cards: initalCards, extraCards: extraCards)
  print(results.map { String($0) }.joined(separator: "\n"))
}

func readExtraCards(count: Int) -> [Int] {
  var cards = [Int]()
  for _ in 0..<count {
    cards.append(readInteger())
  }
  
  return cards
}

func readInteger() -> Int {
  return Int(readLine()!)!
}

func readPairIntegers() -> (Int, Int) {
  let input = readIntegers()
  
  return (input[0], input[1])
}

func readIntegers() -> [Int] {
  return readLine()!.split(separator: " ").map { Int($0)! }
}

func playGame(hp: Int, cards: [Int], extraCards: [Int]) -> [Int] {
  let sortedCards = cards.sorted(by: >)
  
  var results = [Int]()
  var currentTotal = 0
  var heap = Heap<Int>(type: .min)
  
  // inital Setting
  for card in sortedCards {
    guard currentTotal < hp else { break }
    heap.push(card)
    currentTotal += card
  }
  
  results.append(currentTotal >= hp ? heap.count : -1)
  
  // extra Cards
  for card in extraCards {
    defer { results.append(currentTotal >= hp ? heap.count : -1) }
    heap.push(card)
    currentTotal += card
    guard currentTotal >= hp else { continue }

    while let top = heap.top, currentTotal - top >= hp {
      heap.pop()
    }
  }
  
  return results
}

solution()
