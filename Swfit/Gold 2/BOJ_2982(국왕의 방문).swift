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


struct Road {
  let node: Int
  let time: Int
  var godolarVistedTime: (Int, Int) = (-1, -1)
}

struct HeapType: Comparable {
  let node: Int
  let totalTime: Int
  
  init(_ node: Int, _ totalTime: Int) {
    self.node = node
    self.totalTime = totalTime
  }
  
  static func < (lhs: HeapType, rhs: HeapType) -> Bool {
    return lhs.totalTime < rhs.totalTime
  }
}

func solution() {
  let (crossRoadCount, roadCount) = readPair()
  
  let (start, end, timDiff, _) = readTuple()
  let godolarPath = readIntegers().map { $0 - 1 }
  let graph = configureGraph(crossRoadCount, roadCount)
  let godolarGraph = configureGodolar(graph, godolarPath)
//  
//  for i in 0..<godolarGraph.count {
//    print("\(i + 1): \(godolarGraph[i])")
//  }
//  
//  print(godolarGraph)
  let result = dijkstra(godolarGraph, start, end, timDiff)
  print(result)
}

func readTuple() -> (Int, Int, Int, Int) {
  let inputs = readIntegers()
  return (inputs[0], inputs[1], inputs[2], inputs[3])
}

func readPair() -> (Int, Int) {
  let inputs = readIntegers()
  return (inputs[0], inputs[1])
}


func readIntegers() -> [Int] {
  return readLine()!.split(separator: " ").map { Int($0)! }
}

func configureGraph(_ crossRoadCount: Int, _ roadCount: Int) -> [[Road]] {
  var graph = Array(repeating: [Road](), count: crossRoadCount)
  for _ in 0..<roadCount {
    let inputs = readIntegers()
    graph[inputs[0] - 1].append(Road(node: inputs[1] - 1, time: inputs[2]))
    graph[inputs[1] - 1].append(Road(node: inputs[0] - 1, time: inputs[2]))
  }

  return graph
}

func configureGodolar(_ graph: [[Road]], _ godolarPath: [Int]) -> [[Road]] {
  guard godolarPath.count > 1 else { return graph }
  
  var graph = graph
  
  var temp = 0
  var node1 = godolarPath[0]
  for node2 in godolarPath[1...] {
    guard let index1 = graph[node1].firstIndex(where: { $0.node == node2 }),
          let index2 = graph[node2].firstIndex(where: { $0.node == node1 }) else { continue }
    let temp2 = graph[node1][index1].time + temp
    graph[node1][index1].godolarVistedTime = (temp, temp2)
    graph[node2][index2].godolarVistedTime = (temp, temp2)
    temp = temp2
    node1 = node2
  }
  
  return graph
}

func dijkstra(_ graph: [[Road]], _ start: Int, _ end: Int, _ k: Int) -> Int {
  var isVis = Array(repeating: Int.max, count: graph.count)
  isVis[start - 1] = k
  
  var heap = Heap<HeapType>(type: .min)
  heap.push(.init(start - 1, k))
  
  while let top = heap.pop() {
    guard top.node != end - 1 else { continue }
    guard top.totalTime <= isVis[top.node] else { continue }
    
    for road in graph[top.node] {
      var newTotalTime = 0
      if road.godolarVistedTime.0 <= top.totalTime && road.godolarVistedTime.1 > top.totalTime {
        newTotalTime = road.godolarVistedTime.1 + road.time
      } else {
        newTotalTime = top.totalTime + road.time
      }
      
      if newTotalTime < isVis[road.node] {
        isVis[road.node] = newTotalTime
        heap.push(.init(road.node, newTotalTime))
      }
    }
  }

  return isVis[end - 1] - k
}

solution()
