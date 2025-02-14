func solution() {
  let (n, _) = readPairInt()
  let map = configureMap(n)
  let k = readInt()
  let result = maxTurnOnColumn(map, k: k)
  print(result)
}

func readInt() -> Int {
  return Int(readLine()!)!
}

func readPairInt() -> (Int, Int) {
  let inputs = readLine()!.split(separator: " ").map { Int($0)! }
  
  return (inputs[0], inputs[1])
}

func configureMap(_ n: Int) -> [String] {
  var map = [String]()
  
  for _ in 0..<n {
    map.append(readLine()!)
  }
  
  return map
}

func maxTurnOnColumn(_ map: [String], k: Int) -> Int {
  var colZeroCount = Array(repeating: 0, count: map.count)
  var result = 0
  
  for (index, mapRow) in map.enumerated() {
    let zeroCount = mapRow.filter { $0 == "0" }.count
    
    colZeroCount[index] = zeroCount
  }
  
  for index in 0..<map.count {
    let zeroCount = colZeroCount[index]
    guard zeroCount <= k, zeroCount % 2 == k % 2 else { continue }
    
    let count = map.filter { map[index] == $0 }.count
    result = max(result, count)
  }
  
  return result
}

solution()
