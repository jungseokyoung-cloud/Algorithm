func solution() {
  let (guitarCount, _) = readPairInteger()
  let states = configureStates(guitarCount)
  var answerGuitarCount: Int = -1
  var answerSongCount: Int = 0
  
  
  for temp in 0..<(1<<guitarCount) {
    var combination = 0
    
    (0..<guitarCount)
      .filter { (temp >> $0) & 1 == 1 }
      .forEach { combination |= states[$0] }
    
    let result = bitCount(combination)
    let guitarCnt = bitCount(temp)
    
    if answerSongCount < result {
      answerSongCount = result
      answerGuitarCount = guitarCnt
    } else if answerSongCount == result && answerGuitarCount > guitarCnt {
      answerGuitarCount = guitarCnt
    }
  }
  
  print(answerGuitarCount)
}

func readPairInteger() -> (Int, Int) {
  let inputs = readLine()!.split(separator: " ")
  return (Int(inputs[0])!, Int(inputs[1])!)
}

func configureStates(_ count: Int) -> [Int] {
  var states = Array(repeating: 0, count: count)
  
  for i in 0..<count {
    let inputs = readLine()!.split(separator: " ")
    let temp = inputs[1]
    
    for char in temp {
      states[i] = states[i] << 1 | (char == "Y" ? 1 : 0)
    }
  }
  
  return states
}

func bitCount(_ n: Int) -> Int {
  var temp = n
  var cnt = 0
  
  while temp != 0 {
    cnt += (temp & 1)
    temp = temp >> 1
  }
  
  return cnt
}

solution()
