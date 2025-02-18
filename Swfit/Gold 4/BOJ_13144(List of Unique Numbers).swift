func solution() {
  let _ = readLine()
  let numbers = readIntegers()
  let result = uniqueNumbersCount(numbers)
  print(result)
}

func readIntegers() -> [Int] {
  return readLine()!.split(separator: " ").map { Int($0)! }
}

func uniqueNumbersCount(_ numbers: [Int]) -> Int {
  var result = 0
  var isAppear = Array(repeating: false, count: 100001)
  
  var en = 1

  for st in 0..<numbers.count {
    isAppear[numbers[st]] = true
    
    if en <= st { en = st + 1 }
    
    while en < numbers.count, !isAppear[numbers[en]] {
      isAppear[numbers[en]] = true
      en += 1
    }
    
    result += (en - st)
    isAppear[numbers[st]] = false
  }
  return result
}

solution()
