import Foundation

class FileIO {
  @inline(__always) private var buffer: [UInt8] = Array(FileHandle.standardInput.readDataToEndOfFile()) + [0], byteIdx = 0
  
  @inline(__always) private func readByte() -> UInt8 {
    defer { byteIdx += 1 }
    return buffer.withUnsafeBufferPointer { $0[byteIdx] }
  }
  
  @inline(__always) func readInt() -> Int {
    var number = 0, byte = readByte(), isNegative = false
    while byte == 10 || byte == 32 { byte = readByte() }
    if byte == 45 { byte = readByte(); isNegative = true }
    while 48...57 ~= byte { number = number * 10 + Int(byte - 48); byte = readByte() }
    return number * (isNegative ? -1 : 1)
  }
  
  @inline(__always) func readStirngSum() -> Int {
    var byte = readByte()
    while byte == 10 || byte == 32 { byte = readByte() }
    var sum = Int(byte)
    while byte != 10 && byte != 32 && byte != 0 { byte = readByte(); sum += Int(byte) }
    return sum - Int(byte)
  }
  
  @inline(__always) private func write(_ output: String) {
    FileHandle.standardOutput.write(output.data(using: .utf8)!)
  }
}

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

struct QueueItem: Comparable {
  let node: Int
  let cost: Int
  let count: Int
  
  init(_ node: Int, _ cost: Int, _ count: Int) {
    self.node = node
    self.cost = cost
    self.count = count
  }
  
  static func < (lhs: QueueItem, rhs: QueueItem) -> Bool {
    return lhs.cost < rhs.cost
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

func solution() {
  let fileIO = FileIO()
  let (n, m) = readPairInteger(fileIO: fileIO)
  let graph = configureGraph(fileIO: fileIO, rowCount: n, edgeCount: m)
  let result = djikstra(graph: graph, cycle: m)
  print(result)
}

func configureGraph(fileIO: FileIO, rowCount: Int, edgeCount: Int) -> [[(Int, Int)]] {
  var graph = Array(repeating: [(Int, Int)](), count: rowCount)
  
  (0..<edgeCount).forEach { index in
    let (node1, node2) = readPairInteger(fileIO: fileIO)
    graph[node1 - 1].append((node2 - 1, index))
    graph[node2 - 1].append((node1 - 1, index))
  }
  
  return graph
}

func readPairInteger(fileIO: FileIO) -> (Int, Int) {
  let input1 = fileIO.readInt()
  let input2 = fileIO.readInt()
  
  return (input1, input2)
}

func djikstra(graph: [[(Int, Int)]], cycle: Int) -> Int {
  var queue = PriorityQueue<QueueItem>(type: .min)
  var isVis = Array(repeating: Int.max, count: graph.count)
  isVis[0] = 0
  queue.enqueue(.init(0, 0, 0))
  
  while let top = queue.front {
    queue.dequeue()
    
    if top.cost > isVis[top.node] { continue }
    if top.node == graph.count - 1 { return top.cost }
    graph[top.node].forEach { (nextNode, index) in
      var count = top.count
      
      var nextCost = getCost(index: index, cycle: cycle, count: count)
      
      if nextCost < top.cost {
        count += 1
        nextCost = getCost(index: index, cycle: cycle, count: count)
      }
      
      guard nextCost < isVis[nextNode] else { return }
      isVis[nextNode] = nextCost
      queue.enqueue(.init(nextNode, nextCost, count))
    }
  }
  
  return 0
}

func getCost(index: Int, cycle: Int, count: Int) -> Int {
  return index + cycle * count + 1
}

solution()

/*
 N log M
 */
