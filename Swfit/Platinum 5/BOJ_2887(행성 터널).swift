struct UnionFind {
  private var parents: [Int]
  private var ranks: [Int]
  
  init(_ size: Int) {
    self.parents = Array(0...size)
    self.ranks = Array(repeating: 0, count: size + 1)
  }
  
  mutating func findRoot(_ x: Int) -> Int {
    guard x != parents[x] else { return x }
    let parent = findRoot(parents[x])
    parents[x] = parent
    return parent
  }
  
  mutating func union(_ x: Int, _ y: Int) {
    let rootX = findRoot(x)
    let rootY = findRoot(y)
    
    if ranks[rootX] < ranks[rootY] {
      parents[rootX] = rootY
    } else {
      parents[rootY] = rootX
    }
    
    if ranks[rootX] == ranks[rootY] { ranks[rootX] += 1 }
  }
  
  mutating func isSameRoot(_ x: Int, _ y: Int) -> Bool {
    return findRoot(x) == findRoot(y)
  }
}

struct Position {
  let x: Int
  let y: Int
  let z: Int
  
  init(_ x: Int, _ y: Int, _ z: Int) {
    self.x = x
    self.y = y
    self.z = z
  }
}

struct Edge {
  let index1: Int
  let index2: Int
  let distance: Int
  
  init(_ index1: Int, _ index2: Int, _ distance: Int) {
    self.index1 = index1
    self.index2 = index2
    self.distance = distance
  }
}

func solution() {
  let planetCount = readInteger()
  let planets = configurePlanets(planetCount)
  
  if planetCount == 1 { print(0); return; }
  
  var totalCost = 0
  var unionFind = UnionFind(planetCount)
  let edges = configureEdges(planets).sorted { $0.distance < $1.distance }
  
  for edge in edges {
    guard !unionFind.isSameRoot(edge.index1, edge.index2) else { continue }
    unionFind.union(edge.index1, edge.index2)
    totalCost += edge.distance
  }
  
  print(totalCost)
}

func configurePlanets(_ count: Int) -> [Position] {
  var planets: [Position] = []
  
  for _ in 0..<count {
    let (x, y, z) = readTripleInteger()
    planets.append(.init(x, y, z))
  }
  
  return planets
}

func configureEdges(_ planets: [Position]) -> [Edge] {
  var edges = [Edge]()
  
  let xOrderedPlanets = planets.enumerated()
    .map { ($0.0, $0.1.x) }
    .sorted { $0.1 < $1.1 }
  let yOrderedPlanets = planets.enumerated()
    .map { ($0.0, $0.1.y) }
    .sorted { $0.1 < $1.1 }
  let zOrderedPlanets = planets.enumerated()
    .map { ($0.0, $0.1.z) }
    .sorted { $0.1 < $1.1 }
  
  for i in 1..<planets.count {
    let xDistance = abs(xOrderedPlanets[i].1 - xOrderedPlanets[i - 1].1)
    let yDistance = abs(yOrderedPlanets[i].1 - yOrderedPlanets[i - 1].1)
    let zDistance = abs(zOrderedPlanets[i].1 - zOrderedPlanets[i - 1].1)
    
    edges.append(.init(xOrderedPlanets[i].0, xOrderedPlanets[i - 1].0, xDistance))
    edges.append(.init(yOrderedPlanets[i].0, yOrderedPlanets[i - 1].0, yDistance))
    edges.append(.init(zOrderedPlanets[i].0, zOrderedPlanets[i - 1].0, zDistance))
  }
  
  return edges
}

func readInteger() -> Int {
  return Int(readLine()!)!
}

func readTripleInteger() -> (Int, Int, Int) {
  let inputs = readLine()!.split(separator: " ").compactMap { Int($0) }
  
  return (inputs[0], inputs[1], inputs[2])
}

solution()
