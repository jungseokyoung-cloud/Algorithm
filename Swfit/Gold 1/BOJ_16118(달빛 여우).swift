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
  let node: Int
  let cost: Int
  let isEven: Bool
  
  init(_ node: Int, _ cost: Int, _ isEven: Bool) {
    self.node = node
    self.cost = cost
    self.isEven = isEven
  }
  
  init(_ node: Int, _ cost: Int) {
    self.node = node
    self.cost = cost
    self.isEven = false
  }
  
  static func < (lhs: HeapElement, rhs: HeapElement) -> Bool {
    return lhs.cost < rhs.cost
  }
}

func solution() {
  let (n, m) = readPairIntegers()
  let graph = configureGraph(n, m)
  let wolfResults = configureWolf(graph)
  let foxResults = configureFox(graph)
  
  let result = zip(foxResults, wolfResults)
    .filter { $0 < $1 }
    .count
  
  print(result)
}

func readPairIntegers() -> (Int, Int) {
  let inputs = readIntegers()
  
  return (inputs[0], inputs[1])
}

func configureGraph(_ nodeCount: Int, _ vertexCount: Int) -> [[(Int, Int)]] {
  var graph = Array(repeating: [(Int, Int)](), count: nodeCount)
  
  for _ in 0..<vertexCount {
    let (start, end, weight) = readTupleIntegers()
    graph[start - 1].append((end - 1, 2 * weight))
    graph[end - 1].append((start - 1, 2 * weight))
  }
  
  return graph
}

func readTupleIntegers() -> (Int, Int, Int) {
  let inputs = readIntegers()
  
  return (inputs[0], inputs[1], inputs[2])
}

func readIntegers() -> [Int] {
  return readLine()!.split(separator: " ").map { Int($0)! }
}

func configureWolf(_ graph: [[(Int, Int)]]) -> [Int] {
  var results = Array(repeating: (Int.max, Int.max), count: graph.count)
  var heap = Heap<HeapElement>(type: .min)
  results[0].0 = 0
  heap.push(.init(0, 0, false))
  
  while let current = heap.pop() {
    let compareValue = current.isEven ? results[current.node].1 : results[current.node].0
    guard current.cost <= compareValue else { continue }
    
    for (nextNode, weight) in graph[current.node] {
      // 저번이 짝수면 회복, 홀수면 달려
      let nextWeight = current.isEven ? weight * 2 : weight / 2
      let temp = current.cost + nextWeight
      let compareValue = current.isEven ? results[nextNode].0 : results[nextNode].1
      
      guard temp < compareValue else { continue }
      if current.isEven {
        results[nextNode].0 = temp
      } else {
        results[nextNode].1 = temp
      }
      heap.push(.init(nextNode, temp, !current.isEven))
    }
  }
  
  return results.map { min($0.0, $0.1) }
}

func configureFox(_ graph: [[(Int, Int)]]) -> [Int] {
  var results = Array(repeating: Int.max, count: graph.count)
  var heap = Heap<HeapElement>(type: .min)
  results[0] = 0
  heap.push(.init(0, 0, false))
  
  while let current = heap.pop() {
    guard current.cost <= results[current.node] else { continue }
    
    for (nextNode, weight) in graph[current.node] {
      let temp = current.cost + weight
      
      guard temp < results[nextNode] else { continue }
      results[nextNode] = temp
      heap.push(.init(nextNode, temp))
    }
  }
  
  return results
}

solution()
