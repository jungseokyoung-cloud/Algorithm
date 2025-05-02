func solution() {
  let liquidCount = readInteger()
  let liquids = readIntegers()
  
  let result = getMinMixture(liquids)
  print(result.map { "\($0)" } .joined(separator: " "))
}

func readInteger() -> Int {
  return Int(readLine()!)!
}

func readIntegers() -> [Int] {
  return readLine()!.split(separator: " ").map { Int($0)! }
}

func getMinMixture(_ liquids: [Int]) -> [Int] {
  let sortedLiquids = liquids.sorted(by: <)
  var minValue = Int.max
  var results: [Int] = []
  
  for index in 0..<sortedLiquids.count - 2 {
    var en = sortedLiquids.count - 1

    for st in index + 1..<sortedLiquids.count - 1 {
      while en > st {
        let temp = sortedLiquids[st] + sortedLiquids[index] + sortedLiquids[en]
        if abs(temp) < minValue {
          results = [sortedLiquids[index], sortedLiquids[st], sortedLiquids[en]]
          minValue = abs(temp)
        }
        
        if temp < 0 { break }
        en -= 1
      }
    }
  }
  return results
}

solution()

