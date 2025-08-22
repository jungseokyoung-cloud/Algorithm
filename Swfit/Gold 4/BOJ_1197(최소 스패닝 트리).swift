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

struct Edge: Comparable {
  let node: Int
  let cost: Int
  
  init(_ node: Int, _ cost: Int) {
    self.node = node
    self.cost = cost
  }
  
  static func < (lhs: Edge, rhs: Edge) -> Bool {
    return lhs.cost < rhs.cost
  }
}

func solution() {
  let (v, e) = readPairInteger()
  let graph = configureGraph(vertexCount: v, edgeCount: e)
  var queue = Heap<Edge>(type: .min)
  var total = 0
  var isVis = Array(repeating: false, count: v)
  
  for edge in graph[0] { queue.push(edge) }
  isVis[0] = true
  
  while let current = queue.pop() {
    guard !isVis[current.node] else { continue }
    isVis[current.node] = true
    total += current.cost
    
    for edge in graph[current.node] { queue.push(edge) }
  }
  
  print(total)
}


func configureGraph(vertexCount: Int, edgeCount: Int) -> [[Edge]] {
  var graph = Array(repeating: [Edge](), count: vertexCount)
  
  for _ in 0..<edgeCount {
    let (node1, node2, cost) = readTupleInteger()
    graph[node1 - 1].append(.init(node2 - 1, cost))
    graph[node2 - 1].append(.init(node1 - 1, cost))
  }
   
  return graph
}

func readPairInteger() -> (Int, Int) {
  let inputs = readLine()!.split(separator: " ").compactMap { Int($0) }
  return (inputs[0], inputs[1])
}

func readTupleInteger() -> (Int, Int, Int) {
  let inputs = readLine()!.split(separator: " ").compactMap { Int($0) }
  return (inputs[0], inputs[1], inputs[2])
}

solution()
