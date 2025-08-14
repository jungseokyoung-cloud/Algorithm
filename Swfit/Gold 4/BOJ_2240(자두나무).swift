func solution() {
  let (time, w) = readPairInteger()
  let plumMap = configurePlumMap(time).map { $0 - 1 }
  
  var dp = Array(
    repeating: Array(
      repeating: Array(repeating: 0, count: 2),
      count: w + 1
    ),
    count: time + 1
  )
 
  for t in 1...time {
    let plumLocation = plumMap[t - 1]
    let maxMoveCount = min(w, t)

    let adder = plumLocation == 0 ? 1 : 0
    dp[t][0][0] = dp[t-1][0][0] + adder
    for moveCount in 1...maxMoveCount {
      // 움직이는 경우
      dp[t][moveCount][plumLocation] = max(dp[t-1][moveCount - 1][(plumLocation + 1) % 2], dp[t-1][moveCount][plumLocation]) + 1
      dp[t][moveCount][(plumLocation + 1) % 2] = dp[t-1][moveCount][(plumLocation + 1) % 2]
      // 움직이지 않는 경우
    }
  }
  
  print(dp[time].flatMap { $0 }.max() ?? 0)
}

func configurePlumMap(_ t: Int) -> [Int] {
  var plumMap: [Int] = []
  
  for _ in 0..<t { plumMap.append(readInteger()) }
  
  return plumMap
}

func readPairInteger() -> (Int, Int) {
  let inputs = readLine()!.split(separator: " ").map { Int($0)! }
  
  return (inputs[0], inputs[1])
}

func readInteger() -> Int {
  return Int(readLine()!)!
}

solution()
