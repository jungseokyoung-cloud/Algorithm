func solution() {
  let (n, k) = readPairInt()
  let ranges = configureRanges(n)
  let result = resultRange(from: ranges, target: k)
  print("\(result.0) \(result.1)")
}

func readPairInt() -> (Int, Int) {
  let components = readLine()!.split(separator: " ")
  return (Int(components[0])!, Int(components[1])!)
}

func configureRanges(_ n: Int) -> [(Int, Int)] {
  var ranges = [(Int, Int)]()
  for _ in 0..<n {
    ranges.append(readPairInt())
  }
  
  return ranges
}

func resultRange(from ranges: [(Int, Int)], target: Int) -> (Int, Int) {
  let minValue = 0
  let maxValue = 1000000
  var counts = Array(repeating: 0, count: maxValue + 1)
  for range in ranges {
    for i in range.0..<range.1 {
      counts[i] += 1
    }
  }
  
  var en = 1
  var currentSum = counts[minValue]
  for st in minValue...maxValue {
    while en <= maxValue && currentSum < target {
      currentSum += counts[en]
      en += 1
    }
    
    if currentSum == target { return (st, en) }
    currentSum -= counts[st]
  }
  
  return (0, 0)
}

solution()
