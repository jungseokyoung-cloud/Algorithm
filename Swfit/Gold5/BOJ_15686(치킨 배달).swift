struct Point: Equatable {
  let x: Int
  let y: Int
  
  init(_ x: Int, _ y: Int) {
    self.x = x
    self.y = y
  }
}

struct Queue<T> {
  private var elements = [T]()
  private var head = 0
  
  var count: Int { elements.count - head }
  var isEmpty: Bool { count == 0 }
  var front: T? {
    guard !isEmpty else { return nil }
    return elements[head]
  }
  
  mutating func enqueue(_ element: T) {
    elements.append(element)
  }
  
  @discardableResult
  mutating func dequeue() -> T? {
    guard !isEmpty else { return nil }
    defer { head += 1 }
    return elements[head]
  }
}

fileprivate let disX = [-1, 1, 0, 0]
fileprivate let disY = [0, 0, -1, 1]
fileprivate var map = [[Int]]()
fileprivate var totalChickenCount = 0
fileprivate var selectedChickens = [Int]()
fileprivate var chickenDistances = [[Int]]()
fileprivate var result = Int.max

func solution() {
  let (n, m) = readPair()
  totalChickenCount = m
  
  map = configureMap(n)
  totalChickenCount = map.flatMap { $0.filter { $0 >= 1 } }.count
  chickenDistances = chickenDistancesForHouse(from: map)
  
  selectChickens(max: m, index: 1)
  print(result)
}

func configureMap(_ n: Int) -> [[Int]] {
  var map = Array(repeating: [Int](), count: n)
  
  for i in 0..<n { map[i] = readIntegers() }
  
  var chickenIndex = 1
  for i in 0..<n {
    for j in 0..<n {
      guard map[i][j] != 0 else { continue }
      
      if map[i][j] == 1 { map[i][j] = -1 }
      else {
        map[i][j] = chickenIndex
        chickenIndex += 1
      }
    }
  }
  
  
  return map
}

func readPair() -> (Int, Int) {
  let inputs = readIntegers()
  return (inputs[0], inputs[1])
}

func readIntegers() -> [Int] {
  return readLine()!.split(separator: " ").compactMap { Int($0) }
}

func chickenDistancesForHouse(from map: [[Int]]) -> [[Int]] {
  var distances = [[Int]]()
  
  for i in 0..<map.count {
    for j in 0..<map[i].count {
      guard map[i][j] == -1 else { continue }
      distances.append(chickenDistances(from: map, x: i, y: j))
    }
  }
  
  return distances
}

func chickenDistances(from map: [[Int]], x: Int, y: Int) -> [Int] {
  var results = Array(repeating: 0, count: totalChickenCount)
  var isVis = Array(repeating: Array(repeating: -1, count: map[0].count), count: map.count)
  
  var queue = Queue<(Point, Int)>()
  queue.enqueue((.init(x, y), 0))
  isVis[x][y] = 0
  
  while let top = queue.dequeue() {
    let current = top.0
    let value = top.1
    let mapValue = map[current.x][current.y]
    
    if mapValue >= 1 { results[mapValue - 1] = value }
      
    for dir in 0..<4 {
      let nextX = current.x + disX[dir]
      let nextY = current.y + disY[dir]
      
      guard nextX >= 0, nextX < map.count, nextY >= 0, nextY < map[0].count else { continue }
      guard isVis[nextX][nextY] == -1 else { continue }
      isVis[nextX][nextY] = value + 1
      queue.enqueue((.init(nextX, nextY), value + 1))
    }
  }
  
  return results
}

func selectChickens(max: Int, index: Int) {
  if selectedChickens.count == max {
    result = min(result, getResults())
    return
  }
  
  guard index <= totalChickenCount else { return }
  selectedChickens.append(index - 1)
  selectChickens(max: max, index: index + 1)
  selectedChickens.removeLast()
  selectChickens(max: max, index: index + 1)
}

func getResults() -> Int {
  chickenDistances.map {
    $0.enumerated()
      .filter { selectedChickens.contains($0.offset) }
      .map { $0.element }
      .min() ?? 0
  }
  .reduce(0, +)
}

solution()
