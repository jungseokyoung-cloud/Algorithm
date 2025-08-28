import Foundation

struct UnionFind {
  private var parents: [Int]
  private var levels : [Int]
  
  init(_ n: Int) {
    self.parents = Array(0...n)
    self.levels = Array(repeating: 0, count: n + 1)
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
  
  mutating func isSameRoot(_ a: Int, _ b: Int) -> Bool {
    return findRoot(a) == findRoot(b)
  }
}

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
  let (n, m) = readPairInteger()
  let edges = configureEdges(nodeCount: n)
    .sorted { $0.cost < $1.cost }
  var costs = [Int]()
  var unionFind = UnionFind(n)

  for _ in 0..<m {
    let (node1, node2) = readPairInteger()
    unionFind.union(node1 - 1, node2 - 1)
  }
  
  for edge in edges {
    guard !unionFind.isSameRoot(edge.node1, edge.node2) else { continue }
    
    costs.append(edge.cost)
    unionFind.union(edge.node1, edge.node2)
  }
  
  let totalCost = costs.map { sqrt(Double($0)) }.reduce(0, +)
  
  print(roundToTwoDecimalPlaces(totalCost))
}

func configureEdges(nodeCount: Int) -> [Edge] {
  var edges = [Edge]()
  var positions = [(x: Int, y: Int)]()
  
  for _ in 0..<nodeCount {
    positions.append(readPairInteger())
  }
  
  for i in 0..<nodeCount {
    for j in i+1..<nodeCount {
      let dx = positions[i].x - positions[j].x
      let dy = positions[i].y - positions[j].y
      let cost = dx * dx + dy * dy
      edges.append(Edge(i, j, cost))
    }
  }
  
  return edges
}

func readPairInteger() -> (Int, Int) {
  let inputs = readLine()!.split(separator: " ").map { Int($0)! }
  
  return (inputs[0], inputs[1])
}

func roundToTwoDecimalPlaces(_ value: Double) -> String {
    let multiplier = pow(10.0, 2.0)
    let value = (value * multiplier).rounded() / multiplier
  
    return String(format: "%.2f", value)
}

solution()
