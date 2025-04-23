var map = [[Int]]()
var whitePos = [(Int, Int)]()
var blackPos = [(Int, Int)]()
var whiteResult = 0
var blackResult = 0
var leftDiagonalVis: [Bool] = []
var rightDiagonalVis: [Bool] = []


func solution() {
  let size = Int(readLine()!)!
  map = configureMap(size: size)
  setBlackAndWhite(map)
  leftDiagonalVis = Array(repeating: false, count: 2 * map.count)
  rightDiagonalVis = Array(repeating: false, count: 2 * map.count)
  
  trackingWhite(index: 0, count: 0)
  trackingBlack(index: 0, count: 0)
  print(whiteResult + blackResult)
}

func configureMap(size: Int) -> [[Int]] {
  var map: [[Int]] = Array(repeating: [], count: size)
  
  for i in 0..<size {
    let input = readLine()!.split(separator: " ")
    map[i] = input.map { Int(String($0))! }
  }
  
  return map
}

func setBlackAndWhite(_ map: [[Int]]) {
  for i in 0..<map.count {
    for j in 0..<map[0].count {
      guard map[i][j] == 1 else { continue }
      i % 2 == j % 2 ? blackPos.append((i, j)) : whitePos.append((i, j))
    }
  }
}

func trackingWhite(index: Int, count: Int) {
  whiteResult = max(whiteResult, count)
  
  for idx in index..<whitePos.count {
    let leftDiagonalIndex = whitePos[idx].0 - whitePos[idx].1 + map.count - 1
    let rigjtDiagonalIndex = whitePos[idx].0 + whitePos[idx].1
    guard !leftDiagonalVis[leftDiagonalIndex], !rightDiagonalVis[rigjtDiagonalIndex] else { continue }
    leftDiagonalVis[leftDiagonalIndex] = true
    rightDiagonalVis[rigjtDiagonalIndex] = true
    trackingWhite(index: idx + 1, count: count + 1)
    leftDiagonalVis[leftDiagonalIndex] = false
    rightDiagonalVis[rigjtDiagonalIndex] = false
  }
}

func trackingBlack(index: Int, count: Int) {
  blackResult = max(blackResult, count)
  
  for i in index..<blackPos.count {
    let leftDiagonalIndex = blackPos[i].1 - blackPos[i].0 + map.count - 1
    let rigjtDiagonalIndex = blackPos[i].0 + blackPos[i].1
    
    guard !leftDiagonalVis[leftDiagonalIndex], !rightDiagonalVis[rigjtDiagonalIndex] else { continue }
    leftDiagonalVis[leftDiagonalIndex] = true
    rightDiagonalVis[rigjtDiagonalIndex] = true
    trackingBlack(index: i + 1, count: count + 1)
    leftDiagonalVis[leftDiagonalIndex] = false
    rightDiagonalVis[rigjtDiagonalIndex] = false
  }
}

solution()
