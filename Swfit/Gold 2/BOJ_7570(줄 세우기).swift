func solution() {
  let n = readInteger()
  let persons = readIntegers()
  var lengthes = Array(repeating: 0, count: n + 1)
  
  for person in persons {
    lengthes[person] = lengthes[person - 1] + 1
  }
  
  let temp = lengthes.max() ?? 0
  print(n - temp)
}

func readInteger() -> Int {
  return Int(readLine()!)!
}

func readIntegers() -> [Int] {
  return readLine()!.split(separator: " ").map { Int($0)! }
}

solution()
