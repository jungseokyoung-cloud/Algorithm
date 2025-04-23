var result = 0

func solution() {
  let n = readInteger()
  let map = configureMap(n)

  guard n != 1 else { print(map[0][0]); return }

  run2048(turn: 0, map: map)
  print(result)
}

func configureMap(_ col: Int) -> [[Int]] {
  var map = Array(repeating: [Int](), count: col)
  
  for i in (0..<col) {
    map[i] = readIntergers()
  }
  
  return map
}

func readInteger() -> Int {
  return Int(readLine()!)!
}

func readIntergers() -> [Int] {
  return readLine()!.split(separator: " ").map { Int($0)! }
}

func run2048(turn: Int, map: [[Int]]) {
  guard turn < 5 else {
    let maxNum = map.flatMap { $0 }.max() ?? 0
    result = max(result, maxNum)
    return
  }
  
  var temp = map
  
  for dir in 0..<4 {
    let shiftedMap = shift(temp)
    run2048(turn: turn + 1, map: shiftedMap)
    temp = rotateRight(temp)
  }
}

func shift(_ map: [[Int]]) -> [[Int]] {
  let n = map.count
  var temp = map
  
  for i in (0..<n) {
    var lastIndex = 0
    for j in (1..<n) {
      guard temp[i][j] != 0 else { continue }
      
      if lastIndex == -1 || temp[i][lastIndex] != temp[i][j] {
        lastIndex = j
      } else {
        temp[i][lastIndex] *= 2
        temp[i][j] = 0
        lastIndex = -1
      }
    }
    
    var emptyIndex = [Int]()
    var index = 0
    for j in (0..<n) {
      guard temp[i][j] != 0 else {
        emptyIndex.append(j)
        continue
      }

      guard !emptyIndex.isEmpty, index < emptyIndex.count else { continue }
      let insertIndex = emptyIndex[index]
      temp[i][insertIndex] = temp[i][j]
      emptyIndex.append(j)
      temp[i][j] = 0
      index += 1
    }
  }
  
  return temp
}

func rotateRight(_ array: [[Int]]) -> [[Int]] {
  let colCount = array.count
  var temp = array
  
  for i in (0..<colCount) {
    for j in (0..<colCount) {
      temp[j][colCount - i - 1] = array[i][j]
    }
  }
  
  return temp
}

solution()
