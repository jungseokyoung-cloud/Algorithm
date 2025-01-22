func solution() {
  let n = Int(readLine()!)!
  let numbers = configureNumbers(n)
  
  let result = resultOfZero(numbers: numbers)
  print(result)
}

func configureNumbers(_ n: Int) -> [[Int]] {
  var numbers = Array(repeating: [Int](), count: n)
  
  (0..<n).forEach { _ in
    let inputs = readLine()!.split(separator: " ").map { Int($0)! }
    
    inputs.enumerated().forEach {
      numbers[$0.offset].append($0.element)
    }
  }
  
  return numbers
}

func resultOfZero(numbers: [[Int]]) -> Int {
  var result = 0
  
  let sumAandB = configureSumArray(numbers[0], numbers[1])
  
  print(sumAandB)
  
  for numberC in numbers[2] {
    for numberD in numbers[3] {
      let temp = numberC + numberD
      
      let lower = sumAandB.lowerBound(-temp)
      let upper = sumAandB.upperBound(-temp)
      result += (upper - lower)
    }
  }
  
  return result
}

func configureSumArray(_ numbers1: [Int], _ numbers2: [Int]) -> [Int] {
  var results = [Int]()
  
  for num1 in numbers1 {
    for num2 in numbers2 {
      results.append(num1 + num2)
    }
  }
  
  return results.sorted(by: <)
}

extension Array where Element: Comparable {
  func lowerBound(_ target: Element) -> Int {
    var st = 0
    var en = self.count
    
    while st < en {
      let mid = (st + en) / 2
      
      if self[mid] < target {
        st = mid + 1
      } else {
        en = mid
      }
    }
    return en
  }
  
  func upperBound(_ target: Element) -> Int {
    var st = 0
    var en = self.count
    
    while st < en {
      let mid = (st + en) / 2
      
      if self[mid] <= target {
        st = mid + 1
      } else {
        en = mid
      }
    }
    return en
  }
}

solution()
