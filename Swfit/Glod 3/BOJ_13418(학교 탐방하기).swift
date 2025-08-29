enum HeapType {
  case max
  case min
}

// MARK: - Heap
struct Heap<T: Comparable> {
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

struct Road: Comparable {
  let buildingId: Int
  let isUphill: Int
  
  init(_ buildingId: Int, _ isUphill: Int) {
    self.buildingId = buildingId
    self.isUphill = isUphill
  }
  
  static func < (lhs: Road, rhs: Road) -> Bool {
    return lhs.isUphill < rhs.isUphill
  }
}

func solution() {
  let (buildingCount, roadCount) = readPairInteger()
  let roads = configureRoad(buildingCount, roadCount)
  
  let maxValue = totalCost(roads, type: .max)
  let minValue = totalCost(roads, type: .min)
  print(maxValue - minValue)
}

func configureRoad(_ buildingCount: Int, _ roadCount: Int) -> [[Road]] {
  var roads = Array(repeating: [Road](), count: buildingCount + 1)
  
  for _ in 0..<(roadCount + 1) {
    let (from, to, isUphill) = readTripleInteger()
    roads[from].append(Road(to, isUphill == 0 ? 1 : 0))
    roads[to].append(Road(from, isUphill == 0 ? 1 : 0))
  }
  
  return roads
}

func readPairInteger() -> (Int, Int) {
  let inputs = readIntegers()
  return (inputs[0], inputs[1])
}

func readTripleInteger() -> (Int, Int, Int) {
  let inputs = readIntegers()
  return (inputs[0], inputs[1], inputs[2])
}

func readIntegers() -> [Int] {
  return readLine()!.split(separator: " ").compactMap { Int($0) }
}

func totalCost(_ roads: [[Road]], type: HeapType) -> Int {
  var heap = Heap<Road>(type: type)
  var upHillCount = 0
  var isVis = Array(repeating: false, count: roads.count)
  
  roads[0].forEach { heap.push($0) }
  isVis[0] = true
  
  while let current = heap.pop() {
    guard !isVis[current.buildingId] else { continue }
    upHillCount += current.isUphill
    isVis[current.buildingId] = true
        
    for road in roads[current.buildingId].filter({ !isVis[$0.buildingId] }) {
      heap.push(road)
    }
    
  }
  
  return upHillCount * upHillCount
}

solution()
