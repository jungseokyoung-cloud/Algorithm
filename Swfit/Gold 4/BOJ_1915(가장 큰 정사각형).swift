func solution() {
  let (n, _) = readPairInt()
  let squareMap = configureSquareMap(n)
  let result = maxSquareArea(squareMap)
  
  print(result)
}

func configureSquareMap(_ n: Int) -> [[Int]] {
  var squareMap = Array(
    repeating: [Int](),
    count: n
  )
  
  for i in 0..<n {
    let inputs = readLine()!
    
    for input in inputs {
      let num = Int(String(input))!
      squareMap[i].append(num)
    }
  }
  
  return squareMap
}

func readPairInt() -> (Int, Int) {
  let components = readLine()!.split(separator: " ")
  return (Int(components[0])!, Int(components[1])!)
}

func maxSquareArea(_ map: [[Int]]) -> Int {
  var maxSide = 0
  var results = Array(
    repeating: Array(repeating: 0, count: map[0].count),
    count: map.count
  )
  
  for row in 0..<map[0].count {
    results[0][row] = map[0][row]
  }
  
  for col in 1..<map.count {
    results[col][0] = map[col][0]
    for row in 1..<map[0].count {
      guard map[col][row] == 1 else { continue }
      
      let temp = min(results[col - 1][row], results[col][row - 1], results[col - 1][row - 1])
      
      results[col][row] = temp + 1
    }
  }
  
  for col in results {
    for result in col {
      maxSide = max(maxSide, result)
    }
  }
  
  return maxSide * maxSide
}

solution()
