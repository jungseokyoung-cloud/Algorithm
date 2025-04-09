func getSequence(_ col: Int, _ row: Int, _ k: Int) -> Int {
  guard k != 1 else { return col * 2 + row + 1 }
  
  let temp = (1<<(k-1))
  let current = temp * temp
  
  if row < temp && col < temp {
    return getSequence(col, row, k - 1)
  } else if row >= temp && col < temp {
    return current + getSequence(col, row - temp, k - 1)
  } else if row < temp && col >= temp {
    return 2 * current + getSequence(col - temp, row, k - 1)
  } else {
    return 3 * current + getSequence(col - temp, row - temp, k - 1)
  }
}

let inputs = readLine()!.split(separator: " ").map { Int($0)! }
let result = getSequence(inputs[1], inputs[2], inputs[0])
print(result - 1)
