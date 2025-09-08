func solution() {
  let cityCount = readInteger()
  let map = configureMap(cityCount)
  let answer = totalCost(map)
  print(answer)
}

func totalCost(_ map: [[Int]]) -> Int {
  let cityCount = map.count
  var isBasicRoad = Array(
    repeating: Array(repeating: true, count: cityCount),
    count: cityCount
  )
  for i in 0..<cityCount { isBasicRoad[i][i] = false }
  
  for k in 0..<cityCount {
    for i in 0..<cityCount {
      guard i != k else { continue }
      for j in 0..<cityCount {
        guard j != k, j != i else { continue }
        
        if map[i][j] > map[i][k] + map[k][j] { return -1 }
        guard map[i][j] == map[i][k] + map[k][j] else { continue }
        
        isBasicRoad[i][j] = false
      }
    }
  }
  
  let total = zip(isBasicRoad.flatMap { $0 }, map.flatMap { $0 })
    .filter { $0.0 }
    .map { $0.1 }
    .reduce(0, +)
  
  return total / 2
}

func configureMap(_ cityCount: Int) -> [[Int]] {
  var map = [[Int]]()
  
  for _ in 0..<cityCount {
    let integers = readIntegers()
    map.append(integers)
  }
  
  return map
}

func readInteger() -> Int {
  return Int(readLine()!)!
}

func readIntegers() -> [Int] {
  return readLine()!.split(separator: " ").compactMap { Int($0) }
}

solution()
