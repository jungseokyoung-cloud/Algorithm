func solution() {
  let (n, m) = readPairInteger()
  var (distances, longests) = configureDistAndLongest(n, m)
  
  for k in 1...n {
    for i in 1...n {
      for j in 1...n {
        guard distances[i][k] != Int.max, distances[k][j] != Int.max else { continue }
        guard distances[i][k] + distances[k][j] < distances[i][j] else { continue }
        distances[i][j] = distances[i][k] + distances[k][j]
      }
    }
  }
  
  var answer = Int.max
 
  for k in 1...n {
    var temp = 0
    for i in 1...n {
      for j in 1...n {
        guard longests[i][j] != 0, distances[i][k] != Int.max, distances[k][j] != Int.max else { continue }
        let leftBurn = distances[i][k]
        let rightBurn = distances[j][k]
        
        let st = min(leftBurn, rightBurn)
        let burnTime = abs(leftBurn - rightBurn) + (longests[i][j] - abs(leftBurn - rightBurn)) / 2
        
        temp = max(temp, st + burnTime)
      }
    }
    answer = min(answer, temp)
  }
    
  let printValue = answer % 2 == 0 ? "\(answer / 2).0" : "\((answer - 1) / 2).5"
  print(printValue)
}

func readPairInteger() -> (Int, Int) {
  let inputs = readIntegers()
  return (inputs[0], inputs[1])
}

func readTripleInteger() -> (Int, Int, Int) {
  let inputs = readIntegers()
  return (inputs[0], inputs[1], inputs[2])
}

func configureDistAndLongest(_ n: Int, _ m: Int) -> ([[Int]], [[Int]]) {
  var distances = Array(
    repeating: Array(repeating: Int.max, count: n + 1),
    count: n + 1
  )
  var longests = Array(
    repeating: Array(repeating: 0, count: n + 1),
    count: n + 1
  )
  
  for i in 1...n { distances[i][i] = 0 }
  
  for _ in 0..<m {
    let (st, en, len) = readTripleInteger()
    distances[st][en] = min(len * 2, distances[st][en])
    distances[en][st] = min(len * 2, distances[en][st])

    longests[st][en] = max(len * 2, longests[st][en])
    longests[en][st] = max(len * 2, longests[en][st])
  }
  
  return (distances, longests)
}

func readIntegers() -> [Int] {
  return readLine()!.split(separator: " ").compactMap { Int($0) }
}

solution()
