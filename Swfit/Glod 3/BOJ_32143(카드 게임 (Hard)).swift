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
  let hp = readInterger()
  let (_, extraCardCount) = readPairInterger()
  let cardPowers = readIntergers()
  let extraCardPowers = configureExtraCardPower(extraCardCount)
  
  let result = minumunCardCounts(hp, cardPowers, extraCardPowers)
  print(result.map{ String($0) }.joined(separator: "\n"))
}

func configureExtraCardPower(_ extraCardCount: Int) -> [Int] {
  var extraCardPowers: [Int] = []
  
  for _ in 0..<extraCardCount {
    extraCardPowers.append(readInterger())
  }
  
  return extraCardPowers
}

func readInterger() -> Int {
  Int(readLine()!)!
}

func readPairInterger() -> (Int, Int) {
  let inputs = readIntergers()
  
  return (inputs[0], inputs[1])
}

func readIntergers() -> [Int] {
  return readLine()!.split(separator: " ").map { Int($0)! }
}

func minumunCardCounts(_ hp: Int, _ cardPowers: [Int], _ extraCardPowers: [Int]) -> [Int] {
  var results = [Int]()
  var currentCards = Heap<Int>(type: .min)
  let sortedPowers = cardPowers.sorted(by: >)
  var currentTotal = 0
  
  for power in sortedPowers {
    guard currentTotal < hp else { break }
    
    currentTotal += power
    currentCards.push(power)
  }
  
  let result = currentTotal < hp ? -1 : currentCards.count
  results.append(result)

  for extraPower in extraCardPowers {
    if currentTotal < hp {
      currentTotal += extraPower
      currentCards.push(extraPower)
    } else if (currentCards.top ?? 0) < extraPower {
      currentTotal += extraPower
      
      while let top = currentCards.top {
        if currentTotal - top < hp { break }
        currentTotal -= top
        currentCards.pop()
      }

      currentCards.push(extraPower)
    }


    let result = currentTotal < hp ? -1 : currentCards.count
    results.append(result)
  }
  
  return results
}

solution()
