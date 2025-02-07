struct Edge {
  let startNode: Int
  let endNode: Int
  let cost: Int
  
  init(_ startNode: Int, _ endNode: Int, _ cost: Int) {
    self.startNode = startNode
    self.endNode = endNode
    self.cost = cost
  }
}

func solution() {
  let (vertexCount, edgeCount, testCount) = readTupleIntegers()
  let edges = configureEdges(edgeCount)
  let results = configureResultMap(edges, vertexCount)
  
  var printString = ""
  for _ in 0..<testCount {
    let (st, en) = readPairIntegers()
    let temp = results[st - 1][en - 1]
    
    printString += "\(temp == Int.max ? "-1" : "\(temp)")\n"
  }
  print(printString)
}

func configureEdges(_ edgeCount: Int) -> [Edge] {
  var edges = [Edge]()
  
  for _ in 0..<edgeCount {
    let (startVertex, endVertex, cost) = readTupleIntegers()
    edges.append(.init(startVertex - 1, endVertex - 1, cost))
  }
  
  return edges
}

func readTupleIntegers() -> (Int, Int, Int) {
  let inputs = readIntegers()
  
  return (inputs[0], inputs[1], inputs[2])
}

func readPairIntegers() -> (Int, Int) {
  let inputs = readIntegers()
  
  return (inputs[0], inputs[1])
}

func readIntegers() -> [Int] {
  return readLine()!.split(separator: " ").map { Int($0)! }
}

func configureResultMap(_ edges: [Edge], _ vertexCount: Int) -> [[Int]] {
  var results = Array(
    repeating: Array(repeating: Int.max, count: vertexCount),
    count: vertexCount
  )
  
  edges.forEach { edge in
    results[edge.startNode][edge.endNode] = edge.cost
  }
  
  for k in 0..<vertexCount {
    for i in 0..<vertexCount {
      guard k != i else { continue }
      for j in 0..<vertexCount {
        guard j != i, j != k else { continue }
      
        guard results[i][k] != Int.max, results[k][j] != Int.max else { continue }
        let temp = max(results[i][k], results[k][j])
        results[i][j] = min(results[i][j], temp)
      }
    }
  }
  
  return results
}

solution()
