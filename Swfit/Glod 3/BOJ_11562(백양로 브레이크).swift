func solution() {
  let (buildingCount, roadCount) = readPairInteger()
  var map = configureMap(buildingCount, roadCount)
  
  for k in 1..<buildingCount+1 {
    for i in 1..<buildingCount+1 {
      for j in 1..<buildingCount+1 {
        guard map[i][k] != Int.max, map[k][j] != Int.max else { continue }
        
        map[i][j] = min(map[i][j], map[i][k] + map[k][j])
      }
    }
  }
  
  let testCase = Int(readLine()!)!
  var printValue = ""
  
  for _ in 0..<testCase {
    let (st, en) = readPairInteger()
    printValue += "\(map[st][en])\n"
  }
  
  print(printValue)
}

func configureMap(_ buildingCount: Int, _ roadCount: Int) -> [[Int]] {
  var map = Array(
    repeating: Array(repeating: Int.max, count: buildingCount + 1),
    count: buildingCount + 1
  )
  
  for i in 1..<(buildingCount + 1) { map[i][i] = 0 }
  
  for _ in 0..<roadCount {
    let inputs = readIntegers()
    
    map[inputs[0]][inputs[1]] = 0
    map[inputs[1]][inputs[0]] = 0

    if inputs[2] == 0 {
      map[inputs[1]][inputs[0]] = 1
    }
  }
  
  return map
}

func readPairInteger() -> (Int, Int) {
  let inputs = readIntegers()
  return (inputs[0], inputs[1])
}

func readIntegers() -> [Int] {
  return readLine()!.split(separator: " ").compactMap { Int($0) }
}

solution()
