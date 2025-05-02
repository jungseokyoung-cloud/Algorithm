struct ColorBall {
  let color: Int
  let size: Int
}

func solution() {
  let n = readInteger()
  let colorBalls = readColorBalls(n)
  let soretedColorBalls = colorBalls.sorted { $0.size < $1.size }
  let prefixSumTotal = prefixSum(from: soretedColorBalls)
  let prefixSumByColor = prefixSumByColor(from: soretedColorBalls)
  var results = [String]()

  for ball in colorBalls {
    guard let coloredPrefixSum = prefixSumByColor[ball.color] else { fatalError() }
    let totalIndex = lowerBound(from: prefixSumTotal, target: ball.size)
    let coloredTotalIndex = lowerBound(from: coloredPrefixSum, target: ball.size)
    let value = prefixSumTotal[totalIndex - 1] - coloredPrefixSum[coloredTotalIndex - 1]
    results.append("\(value)")
  }
  
  print(results.joined(separator: "\n"))
}

func readColorBalls(_ count: Int) -> [ColorBall] {
  var colorBalls = [ColorBall]()
  
  for _ in 0..<count {
    let input = readPairInteger()
    colorBalls.append(.init(color: input.0, size: input.1))
  }
  
  return colorBalls
}

func prefixSum(from source: [ColorBall]) -> [Int] {
  var results = Array(repeating: 0, count: source.count + 1)
  
  for i in 1..<results.count {
    results[i] = results[i-1] + source[i-1].size
  }
  
  return results
}

func prefixSumByColor(from colorBalls: [ColorBall]) -> [Int: [Int]] {
  var results = [Int: [Int]]()
  
  for colorBall in colorBalls {
    if let existing = results[colorBall.color]?.last {
      results[colorBall.color]?.append(colorBall.size + existing)
    } else {
      results[colorBall.color] = [0, colorBall.size]
    }
  }
  
  return results
}

func readInteger() -> Int {
  return Int(readLine()!)!
}

func readPairInteger() -> (Int, Int) {
  let inputs = readLine()!.split(separator: " ").map { Int($0)! }
  
  return (inputs[0], inputs[1])
}

func lowerBound(from array: [Int], target: Int) -> Int {
  var st = 1
  var en = array.count
  
  while st < en {
    let mid = (st + en) / 2
    let temp = mid == 0 ? array[mid] : array[mid] - array[mid - 1]
    
    if temp < target {
      st = mid + 1
    } else {
      en = mid
    }
  }
  
  return en
}

solution()
