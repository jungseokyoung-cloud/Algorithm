// MARK: - Prime
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

struct Cable: Comparable {
  let cityId: Int
  let cost: Int
  
  init(_ cityId: Int, _ cost: Int) {
    self.cityId = cityId
    self.cost = cost
  }
  
  static func < (lhs: Cable, rhs: Cable) -> Bool {
    return lhs.cost < rhs.cost
  }
}

func solutionPrim() {
  let (cityCount, cableCount, _) = readTripleInteger()
  let powerStation = readIntegers()
  let cables = configureCablesForPrime(cityCount, cableCount)
  
  let cost = totalCostForPrime(cables, powerHouses: powerStation)
  print(cost)
}

func configureCablesForPrime(_ cityCount: Int, _ cableCount: Int) -> [[Cable]] {
  var cables = Array(repeating: [Cable](), count: cityCount + 1)
  
  for _ in 0..<cableCount {
    let (from, to, cost) = readTripleInteger()
    cables[from].append(.init(to, cost))
    cables[to].append(.init(from, cost))
  }
  
  return cables
}

func totalCostForPrime(_ cables: [[Cable]], powerHouses: [Int]) -> Int {
  var heap = Heap<Cable>(type: .min)
  var cost = 0
  var isVis = Array(repeating: false, count: cables.count)
  
  powerHouses.forEach { city in
    isVis[city] = true
    cables[city].forEach { heap.push($0) }
  }
  
  while let current = heap.pop() {
    guard !isVis[current.cityId] else { continue }
    cost += current.cost
    isVis[current.cityId] = true
    for next in cables[current.cityId].filter({ !isVis[$0.cityId] }) {
      heap.push(next)
    }
  }
  
  return cost
}

// MARK: - Kruskal
struct UnionFind {
  private var parents: [Int]
  private var levels: [Int]
  
  init(n: Int) {
    parents = Array(0...n)
    levels = Array(repeating: 0, count: n + 1)
  }
  
  mutating func findRoot(_ x: Int) -> Int {
    guard x != parents[x] else { return x }
    let root = findRoot(parents[x])
    parents[x] = root
    return root
  }
  
  mutating func union(_ a: Int, _ b: Int) {
    let rootA = findRoot(a)
    let rootB = findRoot(b)
    
    if levels[rootA] < levels[rootB] {
      parents[rootA] = rootB
    } else {
      parents[rootB] = rootA
    }
    
    if levels[rootA] == levels[rootB] { levels[rootA] += 1 }
  }
  
  mutating func isSameRoot(_ a: Int, _ b : Int) -> Bool {
    return findRoot(a) == findRoot(b)
  }
}

struct CableKruskal {
  let city1: Int
  let city2: Int
  let cost: Int
  
  init(_ city1: Int, _ city2: Int, _ cost: Int) {
    self.city1 = city1
    self.city2 = city2
    self.cost = cost
  }
}

func solutionKruskal() {
  let (cityCount, cableCount, _) = readTripleInteger()
  let powerStation = readIntegers()
  let cables = configureCableKruscal(cityCount, cableCount)
    .sorted { $0.cost < $1.cost }
  var unionFind = UnionFind(n: cityCount)
  var totalCost = 0
    
  /// 임의의 정점 추가해 powerStation끼리 연결
  for idx in 0..<powerStation.count {
    unionFind.union(0, powerStation[idx])
  }
  
  for cable in cables {
    guard !unionFind.isSameRoot(cable.city1, cable.city2) else { continue }

    totalCost += cable.cost
    unionFind.union(cable.city1, cable.city2)
  }
  
  print(totalCost)
}

func configureCableKruscal(_ cityCount: Int, _ cableCount: Int) -> [CableKruskal] {
  var cables = [CableKruskal]()
  
  for _ in 0..<cableCount {
    let (from, to, cost) = readTripleInteger()
    cables.append(.init(from, to, cost))
  }
  
  return cables
}

// MARK: - Common
func readTripleInteger() -> (Int, Int, Int) {
  let inputs = readIntegers()
  return (inputs[0], inputs[1], inputs[2])
}

func readIntegers() -> [Int] {
  return readLine()!.split(separator: " ").compactMap { Int($0) }
}

solutionKruskal()
