func solution() {
  let count = readInteger()
  let numbers = configureNumbers(count: count)
  
  var total = 0
  let positiveNumbers = numbers.filter { $0 > 1 }.sorted(by: >)
  let minusNumbers = numbers.filter { $0 < 0 }.sorted()
  let oneCount = numbers.filter { $0 == 1 }.count
  let zeroCount = numbers.filter { $0 == 0 }.count
  
  total += oneCount
  total += multipleSum(positiveNumbers)
  if positiveNumbers.count % 2 == 1 { total += positiveNumbers.last! }
  total += multipleSum(minusNumbers)
  if minusNumbers.count % 2 == 1, zeroCount == 0 { total += minusNumbers.last! }
  print(total)
}

func multipleSum(_ numbers: [Int]) -> Int {
  guard numbers.count >= 2 else { return 0 }
  
  var total = 0
  
  for index in stride(from: 0, to: numbers.count, by: +2) {
    guard index + 1 < numbers.count else { break }
    total += numbers[index] * numbers[index + 1]
  }
  
  return total
}

func configureNumbers(count: Int) -> [Int] {
  var numbers = [Int]()
  (0..<count).forEach { _ in numbers.append(readInteger()) }
  
  return numbers
}

func readInteger() -> Int {
  return Int(readLine()!)!
}

solution()
