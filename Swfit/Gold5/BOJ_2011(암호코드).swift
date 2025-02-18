func solution() {
  let input = readLine()!
  let result = availableTextCount(cypher: input)
  print(result)
}

func availableTextCount(cypher: String) -> Int {
  guard cypher.first != "0" else { return 0 }
  
  let cypher = "0" + cypher
  let mod = 1000000
  var results = Array(repeating: 0, count: cypher.count)
  
  results[0] = 1
  results[1] = 1
  
  for index in 2..<cypher.count {
    let currentValue = cypher[index].integerValue()
    let prevValue = cypher[index - 1].integerValue()

    if currentValue == 0 {
      if prevValue == 1 || prevValue == 2 {
        results[index] += results[index - 2]
      } else {
        return 0
      }
    } else {
      results[index] += results[index - 1]
      
      if prevValue == 1 || (prevValue == 2 && currentValue < 7) {
        results[index] += results[index - 2]
        results[index] %= mod
      }
    }
  }
  
  return results[cypher.count - 1] % mod
}

solution()

extension String {
  subscript(idx: Int) -> String {
    let target = index(startIndex, offsetBy: idx)
    return String(self[target])
  }
  
  func integerValue() -> Int {
    return Int(self) ?? 0
  }
}
