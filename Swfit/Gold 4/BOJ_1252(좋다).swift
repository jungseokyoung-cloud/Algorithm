func solution() {
  let _ = Int(readLine()!)
  let numbers = readLine()!
    .split(separator: " ")
    .map { Int($0)! }
    .sorted()
    
  let result = goodCount(numbers)
  
  print(result)
}

func goodCount(_ numbers: [Int]) -> Int {
  var result = 0
  
  for (index, current) in numbers.enumerated() {
    for (searchIndex, searchNumber) in numbers.enumerated() {
      guard searchIndex != index else { continue }
      let target = current - searchNumber
      let lower = lowerBound(from: numbers, target: target)
      let upper = upperBound(from: numbers, target: target)
      var temp = upper - lower
      if (lower..<upper).contains(searchIndex) { temp -= 1 }
      if (lower..<upper).contains(index) { temp -= 1 }
      if temp > 0 { result += 1; break }
    }
  }
  
  return result
}

func lowerBound(from numbers: [Int], target: Int) -> Int {
  var st = 0
  var en = numbers.count
  
  while st < en {
    let mid = (st + en) / 2

    if numbers[mid] >= target { en = mid }
    else { st = mid + 1 }
  }
  
  return en
}

func upperBound(from numbers: [Int], target: Int) -> Int {
  var st = 0
  var en = numbers.count
  
  while st < en {
    let mid = (st + en) / 2
    
    if numbers[mid] > target { en = mid }
    else { st = mid + 1 }
  }
  
  return en
}

solution()
