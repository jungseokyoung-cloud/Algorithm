struct Edge {
  let node1: Int
  let node2: Int
  let cost: Int
  
  init(_ node1: Int, _ node2: Int, _ cost: Int) {
    self.node1 = node1
    self.node2 = node2
    self.cost = cost
  }
}

func solution() {
  let (n, m) = readPairIntegers()
  let edges = configureEdges(m)
  
  let result = minimumDistanceGraph(edges, nodeCount: n)
  let resultString = result.map {
    $0.joined(separator: " ")
  }.joined(separator: "\n")
  print(resultString)
}

func configureEdges(_ edgeCount: Int) -> [Edge] {
  var edges = [Edge]()
  
  for _ in 0..<edgeCount {
    let (u, v, cost) = readTupleIntegers()
    edges.append(.init(u - 1, v - 1, cost))
  }
  
  return edges
}

func readPairIntegers() -> (Int, Int) {
  let inputs = readIntegers()
  
  return (inputs[0], inputs[1])
}

func readTupleIntegers() -> (Int, Int, Int) {
  let inputs = readIntegers()
  
  return (inputs[0], inputs[1], inputs[2])
}

func readIntegers() -> [Int] {
  return readLine()!.split(separator: " ").map { Int($0)! }
}

func minimumDistanceGraph(_ edges: [Edge], nodeCount: Int) -> [[String]] {
  var results = Array(
    repeating: Array(repeating: Int.max, count: nodeCount),
    count: nodeCount
  )
  var trace = Array(
    repeating: Array(repeating: "-", count: nodeCount),
    count: nodeCount
  )
  
  edges.forEach {
    results[$0.node1][$0.node2] = $0.cost
    results[$0.node2][$0.node1] = $0.cost
    trace[$0.node1][$0.node2] = "\($0.node2+1)"
    trace[$0.node2][$0.node1] = "\($0.node1+1)"
  }
  
  for i in 0..<nodeCount {
    results[i][i] = 0
  }
  
  for k in 0..<nodeCount {
    for i in 0..<nodeCount {
      guard i != k else { continue }
      for j in 0..<nodeCount {
        guard i != j && j != k else { continue }
        
        guard results[i][k] != Int.max, results[k][j] != Int.max else { continue }
        
        let temp = results[i][k] + results[k][j]
        if results[i][j] > temp {
          results[i][j] = temp
          trace[i][j] = trace[i][k]
        }
      }
    }
  }
  
  
  return trace
}

solution()
