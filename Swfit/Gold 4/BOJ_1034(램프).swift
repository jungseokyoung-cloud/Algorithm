func solution() {
  let (n, _) = readPairIntegers()
  let map = configureMap(n)
  let orderBySameCol = orderdBySameCol(map)
  let k = readInteger()
  
  let result = orderBySameCol
    .filter { (key, value) -> Bool in
      let zeroCount = key.filter { $0 == "0" }.count
      return zeroCount <= k && zeroCount % 2 == k % 2
    }
    .map { $0.value }
    .sorted(by: >)
  print(result.first ?? 0)
}

func configureMap(_ n: Int) -> [String] {
  var map = [String]()
  
  for _ in 0..<n { map.append(readLine()!) }
  
  return map
}

func orderdBySameCol(_ map: [String]) -> [String: Int] {
  var results = [String: Int]()
  
  for col in map {
    results[col, default: 0] += 1
  }
  
  return results
}

func readPairIntegers() -> (Int, Int) {
  let inputs = readLine()!.split(separator: " ").map { Int($0)! }
  return (inputs[0], inputs[1])
}

func readInteger() -> Int {
  return Int(readLine()!)!
}

solution()
