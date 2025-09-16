func solution() {
  let (n, m) = readPairInteger()
  let numbers = readIntegers()
  let accumulatedSum = numbers.enumerated().reduce(into: [Int](repeating: 0, count: n + 1)) { result, element in
    result[element.offset + 1] = result[element.offset] + element.element
  }[1..<n+1]
  var remainderCnt = Array(repeating: 0, count: m + 1)
  remainderCnt[0] = 1
  var answer = 0
  
  for (index, current) in accumulatedSum.enumerated() {
    let remainder = current % m
      
    answer += remainderCnt[remainder]
    remainderCnt[remainder] += 1
  }
  
  print(answer)
}

func readIntegers() -> [Int] {
  return readLine()!.split(separator: " ").compactMap { Int($0) }
}

func readPairInteger() -> (Int, Int) {
  let inputs = readIntegers()
  
  return (inputs[0], inputs[1])
}

solution()
