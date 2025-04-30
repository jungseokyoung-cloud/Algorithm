fileprivate var isPossible = false
fileprivate var maxWinCount = 0
fileprivate var playInformations = [[Int]]()
fileprivate var gameInformations = [[Int]]()
fileprivate var isUsed = [Bool]()

func solution() {
  let (cnt, winCount) = readPairIntegers()
  maxWinCount = winCount
  configureGameInfo(cnt)
  configurePlayInfo(2)
  isUsed = Array(repeating: false, count: cnt + 1)
  let winCounts = Array(repeating: 0, count: 3)
  
  run(opponent: 1, winCounts: winCounts, player2Index: 0, player3Index: 0)
  
  let result = isPossible ? 1 : 0
  print(result)
}

func configureGameInfo(_ n: Int) {
  gameInformations = Array(
    repeating: [Int](),
    count: n + 1
  )
  
  for i in 1...n {
    let inputs = readIntegers()
    gameInformations[i].append(0)
    gameInformations[i].append(contentsOf: inputs)
  }
}

func configurePlayInfo(_ playerCount: Int) {
  playInformations = Array(repeating: [Int](), count: playerCount)
  
  for i in 0..<playerCount {
    playInformations[i] = readIntegers()
  }
}

func readPairIntegers() -> (Int, Int) {
  let inputs = readIntegers()
  return (inputs[0], inputs[1])
}

func readIntegers() -> [Int] {
  return readLine()!.split(separator: " ").map { Int($0)! }
}

func run(opponent: Int, winCounts: [Int], player2Index: Int, player3Index: Int) {
  guard !isPossible else { return }
  
  if player2Index >= 20 && opponent == 1 || player3Index >= 20 && opponent == 2 {
    return
  }
 
  if winCounts[0] == maxWinCount { isPossible = true; return; }
  guard !winCounts.contains(where: { $0 >= maxWinCount }) else { return }

  let index = opponent == 1 ? player2Index : player3Index
  let opponentValue = playInformations[opponent - 1][index]
  
  for value in 1..<gameInformations.count {
    guard !isUsed[value] else { continue }
    var winCounts = winCounts
    var player2Index = player2Index
    var player3Index = player3Index

    isUsed[value] = true
    let temp = gameInformations[value][opponentValue]
    if opponent == 1 {
      player2Index += 1
    } else {
      player3Index += 1
    }
    
    if temp == 2 {
      winCounts[0] += 1
      let nextOpponent = opponent == 1 ? 2 : 1
   
      run(opponent: nextOpponent, winCounts: winCounts, player2Index: player2Index, player3Index: player3Index)
    // 지거나 비기는 경우
    } else {
      winCounts[opponent] += 1
      let player2Value = playInformations[0][player2Index]
      let player3Value = playInformations[1][player3Index]
      let result = gameInformations[player2Value][player3Value]
      let nextOpponent = result == 2 ? 1 : 2
      winCounts[nextOpponent] += 1
      player2Index += 1
      player3Index += 1
      
      run(opponent: nextOpponent, winCounts: winCounts, player2Index: player2Index, player3Index: player3Index)
    }
    isUsed[value] = false
  }
}

solution()
