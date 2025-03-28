//// MARK: - Heap
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

struct Item: Comparable {
  let id: Int
  var nextIndex: Int
  
  init(_ id: Int, _ nextIndex: Int) {
    self.id = id
    self.nextIndex = nextIndex
  }
  
  static func < (lhs: Item, rhs: Item) -> Bool {
    return lhs.nextIndex < rhs.nextIndex
  }
}

func solutiuon(_ n: Int, _ pages: [Int]) -> Int {
  var victimCount = 0
  var isInMultitap = Array(repeating: false, count: pages.count + 1)
  var multiTap = [Item]()
  
  for (index, page) in pages.enumerated() {
    let nextIdx = nextIndex(for: index, from: pages)

    guard !isInMultitap[page] else {
      let idx = multiTap.firstIndex { $0.id == page }!
      multiTap[idx].nextIndex = nextIdx
      continue
    }
    let item = Item(page, nextIdx)
    
    if multiTap.count >= n {
      let (index, element) = multiTap.enumerated().sorted { $0.element < $1.element }.last!
      victimCount += 1
      multiTap.remove(at: index)
      isInMultitap[element.id] = false
    }
    multiTap.append(item)
    isInMultitap[page] = true
  }
  
  return victimCount
}

func nextIndex(for index: Int, from pages: [Int]) -> Int {
  guard index != pages.count - 1 else { return 200 }
  let target = pages[index]
  
  for idx in index + 1..<pages.count {
    if pages[idx] == target { return idx }
  }
  
  return 200
}

func readPairIntegers() -> (Int, Int) {
  let inputs = readIntegers()
  
  return (inputs[0], inputs[1])
}

func readIntegers() -> [Int] {
  return readLine()!.split(separator: " ").compactMap(String.init).compactMap(Int.init)
}

let (n, _) = readPairIntegers()
let pages = readIntegers()
let result = solutiuon(n, pages)
print(result)
/*
4 20
1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5
 */
