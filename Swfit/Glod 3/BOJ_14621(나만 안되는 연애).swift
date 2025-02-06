struct UnionFind {
  private var parent: [Int]
  
  init(elementCount: Int) {
    parent = Array(repeating: -1, count: elementCount)
    
    for i in 0..<elementCount { parent[i] = i }
  }
  
  mutating func union(_ x: Int, and y: Int) -> Bool {
    let xParent = getParent(for: x)
    let yParent = getParent(for: y)
    
    if xParent == yParent { return false }
    
    if xParent < yParent {
      parent[yParent] = xParent
    } else {
      parent[xParent] = yParent
    }
    
    return true
  }
  
  mutating func getParent(for x: Int) -> Int {
    guard parent[x] != x else { return x }
    
    parent[x] = getParent(for: parent[x])
    return parent[x]
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
  let inputs = readIntegers()
  let roadCount = inputs[1]
  let genderInfo = readStrings()
  let roads = configureRoads(roadCount)
  
  let result = minimumRoadCost(roads, genderInfo)
  print(result)
}

func configureRoads(_ roadCount: Int) -> [Edge] {
  var roads = [Edge]()
  
  for _ in 0..<roadCount {
    let inputs = readIntegers()
    roads.append(.init(inputs[0] - 1, inputs[1] - 1, inputs[2]))
  }
  
  return roads
}

func readStrings() -> [String] {
  return readLine()!.split(separator: " ").map { String($0) }
}

func readIntegers() -> [Int] {
  return readLine()!.split(separator: " ").map { Int($0)! }
}

func minimumRoadCost(_ roads: [Edge], _ genderInfo: [String]) -> Int {
  var unionFind = UnionFind(elementCount: genderInfo.count)
  var totalCost = 0
  
  for road in roads.sorted(by: { $0.cost < $1.cost }) {
    let university1 = road.node1
    let university2 = road.node2
    
    guard genderInfo[university1] != genderInfo[university2] else { continue }
    
    if unionFind.union(university1, and: university2) {
      totalCost += road.cost
    }
  }
  
  let parent = unionFind.getParent(for: 0)
  for i in 0..<genderInfo.count {
    let tempParent = unionFind.getParent(for: i)
    
    guard parent == tempParent else { return -1 }
  }
  
  return totalCost
}

solution()
