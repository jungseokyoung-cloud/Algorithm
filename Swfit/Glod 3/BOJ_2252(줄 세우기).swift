struct Queue<T> {
  private var elements = [T]()
  private var index = 0
  
  var count: Int { elements.count - index }
  var isEmpty: Bool { count == 0 }
  
  mutating func enqueue(_ element: T) {
    elements.append(element)
  }
  
  mutating func dequeue() -> T? {
    guard !isEmpty else { return nil }
    defer { index += 1 }
    return elements[index]
  }
}

func solution() {
  let (personCount, compareCount) = readPairInteger()
  let graph = configureGraph(nodeCount: personCount, edgeCount: compareCount)
  var indegrees = configureIndegreeArray(graph: graph)
  
  var queue = Queue<Int>()
  var results = [Int]()
  
  let inputs = indegrees.enumerated()
    .filter { $1 == 0 }
    .map { $0.offset }

  inputs.filter { $0 != 0 }.forEach { queue.enqueue($0) }
  
  while let current = queue.dequeue() {
    results.append(current)
    
    graph[current].forEach {
      indegrees[$0] -= 1
      if indegrees[$0] == 0 {
        queue.enqueue($0)
      }
    }
  }
  
  let output = results.map { "\($0)" }.joined(separator: " ")
  print(output)
}

func readPairInteger() -> (Int, Int) {
  let inputs = readLine()!.split(separator: " ").map { Int($0)! }
  return (inputs[0], inputs[1])
}

func configureGraph(nodeCount: Int, edgeCount: Int) -> [[Int]] {
  var graph = Array(repeating: [Int](), count: nodeCount + 1)
  
  (0..<edgeCount).forEach { _ in
    let (start, end) = readPairInteger()
    graph[start].append(end)
  }
  
  return graph
}

func configureIndegreeArray(graph: [[Int]]) -> [Int] {
  var indegreeArray = Array(repeating: 0, count: graph.count)
  
  for edges in graph {
    edges.forEach { indegreeArray[$0] += 1 }
  }
  
  return indegreeArray
}

solution()
