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

struct UnionFind {
  private var parents: [Int]
  private var levels: [Int]
  
  init(_ n: Int) {
    parents = Array(repeating: 0, count: n)
    levels = Array(repeating: 0, count: n)

    for i in 0..<n { parents[i] = i }
  }
  
  mutating func find(_ x: Int) -> Int {
    guard parents[x] != x else { return x }
    let parent = find(parents[x])
    parents[x] = parent
    return parent
  }
  
  mutating func union(_ x: Int, _ y: Int) {
    let rootX = find(x)
    let rootY = find(y)
    
    if levels[rootX] == levels[rootY] {
      levels[rootX] += 1
    }
  
    if levels[rootX] > levels[rootY] {
      parents[rootY] = rootX
    } else {
      parents[rootX] = rootY
    }
  }
  
  mutating func isSameRoot(_ x: Int, _ y: Int) -> Bool {
    return find(x) == find(y)
  }
}

func kruskalSolution() {
  let numberOfPlanets = readInteger()
  let edges = configureEdges(numberOfPlanets)
  let sortedEdges = edges.sorted { $0.cost < $1.cost }
  
  var total = 0
  var unionFind = UnionFind(numberOfPlanets)
  
  for edge in sortedEdges {
    guard !unionFind.isSameRoot(edge.node1, edge.node2) else { continue }
    total += edge.cost
    unionFind.union(edge.node1, edge.node2)
  }
  
  print(total)
}

func configureEdges(_ cnt: Int) -> [Edge] {
  var edges = [Edge]()
  
  for idx in 0..<cnt {
    let input = readIntegers()
    
    for (index, cost) in input.enumerated() {
      guard index < idx else { continue }
      edges.append(.init(idx, index, cost))
    }
  }
  
  return edges
}

func readInteger() -> Int {
  return Int(readLine()!)!
}

func readIntegers() -> [Int] {
  return readLine()!.split(separator: " ").compactMap { Int($0) }
}

kruskalSolution()
