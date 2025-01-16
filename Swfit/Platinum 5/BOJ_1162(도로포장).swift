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

struct PriorityQueue<T: Comparable> {
  private var heap: Heap<T>
  
  var isEmpty: Bool { heap.isEmpty }
  var count: Int { heap.count }
  var front: T? { heap.peek }
  
  init(type: Heap<T>.HeapType) {
    self.heap = Heap(type: type)
  }
  
  mutating func enqueue(_ element: T) {
    heap.push(element)
  }
  
  @discardableResult
  mutating func dequeue() -> T? {
    return heap.pop()
  }
}

struct QueueItem {
  let node: Int
  let k: Int
  let cost: Int
  
  init(_ node: Int, _ k: Int, _ cost: Int) {
    self.node = node
    self.k = k
    self.cost = cost
  }
}

extension QueueItem: Comparable {
  static func < (lhs: QueueItem, rhs: QueueItem) -> Bool {
    return lhs.cost < rhs.cost
  }
}

func solution() {
  let (cityCount, roadCount, k) = readTupleIntegers()
  
  let roads = configureRoads(cityCount: cityCount, roadCount: roadCount)
  let result = dijkstra(roads: roads, k: k)
  print(result)
}

func configureRoads(cityCount: Int, roadCount: Int) -> [[(Int, Int)]] {
  var graph = Array(repeating: [(Int, Int)](), count: cityCount)
  
  (0..<roadCount).forEach { _ in
    let (city1, city2, weight) = readTupleIntegers()
    graph[city1 - 1].append((city2 - 1, weight))
    graph[city2 - 1].append((city1 - 1, weight))
  }
  
  return graph
}

func readTupleIntegers() -> (Int, Int, Int) {
  let inputs = readLine()!.split(separator: " ").map { Int($0)! }
  
  return (inputs[0], inputs[1], inputs[2])
}

func dijkstra(roads: [[(Int, Int)]], k: Int) -> Int {
  var queue = PriorityQueue<QueueItem>(type: .min)
  var costs = Array(
    repeating: Array(repeating: Int.max, count: k + 1),
    count: roads.count
  )
  costs[0][k] = 0
  queue.enqueue(.init(0, k, 0))
  
  while let front = queue.dequeue() {
    guard costs[front.node][front.k] >= front.cost else { continue }

    roads[front.node].forEach { (toCity, weight) in
      let nextCost = front.cost + weight
      
      // 지우지 않는 방식
      if costs[toCity][front.k] > nextCost {
        costs[toCity][front.k] = nextCost
        queue.enqueue(.init(toCity, front.k, nextCost))
      }
      
      if front.k != 0 && costs[toCity][front.k - 1] > front.cost {
        costs[toCity][front.k - 1] = front.cost
        queue.enqueue(.init(toCity, front.k - 1, front.cost))
      }
    }
  }
  
  return costs[roads.count - 1].min() ?? 0
}

solution()
