func solution() {
  let inputs = readIntegers()
  let _ = inputs[0]
  let capacity = inputs[1]
  let assens = readIntegers().sorted(by: <)
  
  let result = maxBottleCount(assens: assens, capacity: capacity)
  print(result)
}

func readIntegers() -> [Int] {
  readLine()!.split(separator: " ").map { Int($0)! }
}

func maxBottleCount(assens: [Int], capacity: Int) -> Int {
  let remainAssens = assens.filter { $0 < capacity }
  var en = remainAssens.count - 1
  var count = assens.count - remainAssens.count
  var remainBottleCount = remainAssens.count

  for st in 0..<remainAssens.count {
    guard st < en else { break }

    let total = recycle(assens[st], and: assens[en], capacity: capacity)
    if total >= Double(capacity) {
      count += 1
      remainBottleCount -= 2
      en -= 1
    }
  }

  return remainBottleCount == 0 ? count : count + remainBottleCount / 3
}

func recycle(_ assensA: Int, and assensB: Int, capacity: Int) -> Double {
  Double(assensA + assensB) + Double(capacity) / 2
}

solution()
