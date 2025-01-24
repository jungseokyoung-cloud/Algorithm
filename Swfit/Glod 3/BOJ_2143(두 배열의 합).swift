func solution() {
  let target = readInt()
  let _ = readInt()
  let arrayA = readIntegers()
  let _ = readInt()
  let arrayB = readIntegers()
  let result = countFor(sum: target, from: arrayA, and: arrayB)
  print(result)
}

func readInt() -> Int {
  return Int(readLine()!)!
}

func readIntegers() -> [Int] {
  return readLine()!.split(separator: " ").map { Int($0)! }
}

func countFor(
  sum: Int,
  from arrayA: [Int],
  and arrayB: [Int]
) -> Int {
  var result = 0
  let sumArrayA = configureSumArray(arrayA)
  let sumArrayB = configureSumArray(arrayB).sorted(by: <)

  for sumA in sumArrayA {
    let target = sum - sumA

    let lower = sumArrayB.lowerBound(target)
    let upper = sumArrayB.upperBound(target)
    
    result += (upper - lower)
  }
  
  return result
}

func configureSumArray(_ array: [Int]) -> [Int] {
  var array = array
  var results = [Int]()

  for index in 1..<array.count {
    array[index] += array[index - 1]
  }
  for index1 in 0..<array.count {
    results.append(array[index1])

    for index2 in index1+1..<array.count {
      results.append(array[index2] - array[index1])
    }
  }
  
  return results
}

extension Array where Element: Comparable {
  func lowerBound(_ target: Element) -> Int {
    var st = 0
    var en = count
    
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
    var en = count
    
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
