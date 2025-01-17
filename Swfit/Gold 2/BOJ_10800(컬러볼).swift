struct ColorBall {
  let index: Int
  let color: Int
  var size: Int
  
  init(_ index: Int, _ color: Int, _ size: Int) {
    self.index = index
    self.color = color
    self.size = size
  }
}

func solution() {
  let n = readInteger()
  var colorBalls = [ColorBall]()
  
  (0..<n).forEach { index in
    let (color, size) = readPairIntegers()
    colorBalls.append(.init(index, color, size))
  }
  
  let result = getScores(colorBalls: colorBalls)
  let resultString = result.map { "\($0)" }.joined(separator: "\n")
  print(resultString)
}

func getScores(colorBalls: [ColorBall]) -> [Int] {
  var results = Array(repeating: 0, count: colorBalls.count)
  var scoreByColor = Array(repeating: 0, count: colorBalls.count + 1)
  let sortedBySize = colorBalls.sorted {
    ($0.size == $1.size) ? $0.color < $1.color : $0.size < $1.size
  }

  var tempScore = sortedBySize[0].size
  scoreByColor[sortedBySize[0].color] = sortedBySize[0].size

  var duplicateScore = 0
  var sameColorDuplicateScore = 0
  
  sortedBySize.enumerated().forEach { (index, colorBall) in
    guard index != 0 else { return }
    
    if colorBall.size == sortedBySize[index - 1].size {
      duplicateScore += colorBall.size
      
      if colorBall.color == sortedBySize[index - 1].color {
        sameColorDuplicateScore += colorBall.size
      } else {
        sameColorDuplicateScore = 0
      }
    } else {
      duplicateScore = 0
      sameColorDuplicateScore = 0
    }
    results[colorBall.index] = tempScore - scoreByColor[colorBall.color] - duplicateScore + sameColorDuplicateScore

    scoreByColor[colorBall.color] += colorBall.size
    tempScore += colorBall.size
  }
  
  return results
}

func readInteger() -> Int {
  return Int(readLine()!)!
}

func readPairIntegers() -> (Int, Int) {
  let inputs = readLine()!.split(separator: " ").map { Int($0)! }
  
  return (inputs[0], inputs[1])
}

solution()
