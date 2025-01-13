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

struct PriorityQueue<T: Comparable> {
  private var heap: Heap<T>
  
  var count: Int { heap.count }
  var isEmpty: Bool { heap.isEmpty }
  var front: T? { heap.top }
  
  init(type: Heap<T>.HeapType) {
    self.heap = Heap(type: type)
  }
}

// MARK: - Methods
extension PriorityQueue {
  mutating func enqueue(_ element: T) {
    heap.push(element)
  }
  
  @discardableResult
  mutating func dequeue() -> T? {
    return heap.pop()
  }
}

struct Edge: Comparable {
  let node: Int
  let cost: Int
  
  init(_ destination: Int, _ cost: Int) {
    self.node = destination
    self.cost = cost
  }
  
  static func < (lhs: Edge, rhs: Edge) -> Bool {
    return lhs.cost < rhs.cost
  }
}

func solution() {
  let (n, m, _) = readInformation()
  let graph = configureGraph(nodeCount: n, edgeCount: m)
  let interviewRooms = readIntegers().map { $0 - 1 }

  let result = dijkstra(graph: graph, interviewRooms: interviewRooms)
  
  let resultString = "\(result.0)\n\(result.1)"
  print(resultString)
}

func readIntegers() -> [Int] {
  return readLine()!.split(separator: " ").map { Int($0)! }
}

func readInformation() -> (Int, Int, Int) {
  let inputs = readIntegers()
  return (inputs[0], inputs[1], inputs[2])
}

func configureGraph(nodeCount: Int, edgeCount: Int) -> [[Edge]] {
  var graph = Array(repeating: [Edge](), count: nodeCount)
  
  (0..<edgeCount).forEach { _ in
    let (st, en, cost) = readInformation()
    graph[en - 1].append(.init(st - 1, cost))
  }
  
  return graph
}

func dijkstra(graph: [[Edge]], interviewRooms: [Int]) -> (Int, Int) {
  var isVis = Array(repeating: Int.max, count: graph.count)
  var queue = PriorityQueue<Edge>(type: .min)
  
  interviewRooms.forEach {
    isVis[$0] = 0
    queue.enqueue(.init($0, 0))
  }
  
  while let top = queue.front {
    queue.dequeue()
    
    if isVis[top.node] < top.cost { continue }

    graph[top.node].forEach { edge in
      let nextNode = edge.node
      let nextCost = top.cost + edge.cost
      
      guard nextCost < isVis[nextNode] else { return }
      isVis[nextNode] = nextCost
      queue.enqueue(.init(nextNode, nextCost))
    }
  }
  
  var maxCostIndex: Int = 0
  
  for index in isVis.indices {
    if isVis[maxCostIndex] < isVis[index] {
      maxCostIndex = index
    }
  }

  return (maxCostIndex + 1, isVis[maxCostIndex])
}

solution()
