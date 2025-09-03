func solution() {
  let cityCount = readInteger()
  let busCount = readInteger()
  
  var (map, trace) = configureMap(cityCount, busCount)
  
  for k in 1...cityCount {
    for i in 1...cityCount {
      for j in 1...cityCount {
        guard map[i][k] != Int.max, map[k][j] != Int.max else { continue }
        guard map[i][j] > map[i][k] + map[k][j] else { continue }
    
        map[i][j] = map[i][k] + map[k][j]
        trace[i][j] = trace[i][k]
      }
    }
  }
  
  var answer = map[1...cityCount]
    .map {
      $0[1...cityCount].map { $0 == Int.max ? 0 : $0 }
        .map { String($0) }
        .joined(separator: " ")
    }
    .joined(separator: "\n")
  
  answer += "\n"
  
  for i in 1...cityCount {
    for j in 1...cityCount {
      guard i != j else { answer += "0\n"; continue }
      guard map[i][j] != Int.max else { answer += "0\n"; continue }
      
      var path = [Int]()
      var st = i
      
      while st != j {
        path.append(st)
        st = trace[st][j]
      }
      
      path.append(j)
      let pathString = path.map { String($0) }.joined(separator: " ")
      answer += "\(path.count) \(pathString)\n"
    }
  }
  
  print(answer)
}

func readInteger() -> Int {
  return Int(readLine()!)!
}

func configureMap(_ cityCount: Int, _ busCount: Int) -> (map: [[Int]], trace: [[Int]]) {
  var map = Array(
    repeating: Array(repeating: Int.max, count: cityCount + 1),
    count: cityCount + 1
  )
  
  var trace = Array(
    repeating: Array(repeating: 0, count: cityCount + 1),
    count: cityCount + 1
  )
  
  for i in 1..<cityCount + 1 { trace[i][i] = i }
  
  for i in 1..<cityCount + 1 { map[i][i] = 0 }
  
  for _ in 0..<busCount {
    let (st, en, cost) = readTripleInteger()
    map[st][en] = min(cost, map[st][en])
    trace[st][en] = en
  }
  
  return (map, trace)
}

func readTripleInteger() -> (Int, Int, Int) {
  let inputs = readLine()!.split(separator: " ").map { Int($0)! }
  
  return (inputs[0], inputs[1], inputs[2])
}

solution()
