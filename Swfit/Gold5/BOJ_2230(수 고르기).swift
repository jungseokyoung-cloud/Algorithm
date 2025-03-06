func solution() {
  let (n, target) = readPairIntegers()
  let numbers = configureNumbers(n)
  let result = overTargetCount(numbers, target: target)
  
  print(result)
}

func configureNumbers(_ n: Int) -> [Int] {
  var numbers = [Int]()
  
  for _ in 0..<n {
    numbers.append(readIntger())
  }
  
  return numbers
}

func readPairIntegers() -> (Int, Int) {
  let inputs = readLine()!.split(separator: " ").map { Int($0)! }
  return (inputs[0], inputs[1])
}

func readIntger() -> Int {
  return Int(readLine()!)!
}

func overTargetCount(_ numbers: [Int], target: Int) -> Int {
  var result = Int.max
  let sortedNumbers = numbers.sorted()
  var en = 1
  
  for st in 0..<sortedNumbers.count {
    if en == st { en = st + 1 }
    while en < sortedNumbers.count, sortedNumbers[en] - sortedNumbers[st] < target {
      en += 1
    }
    guard en < sortedNumbers.count else { break }
    
    if sortedNumbers[en] - sortedNumbers[st] >= target {
      result = min(result, sortedNumbers[en] - sortedNumbers[st])
    }
  }
  
  return result
}

solution()
