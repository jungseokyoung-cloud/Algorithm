let _ = readLine()!
var numbers = readLine()!.split(separator: " ").map { Int($0)! }
var movedLog = [[Int]]()
var anserAvailable = false

func solution(from index1: Int, to index2: Int) {
  guard anserAvailable == false else { return }

  if isAvailable(numbers) {
    printAnswer()
    anserAvailable = true
    return
  }
  
  guard movedLog.count < 2 else { return }
  if
    let frontStartIndex = numbers.enumerated().first(where: { $0.element != $0.offset + 1})?.offset,
    let frontEndIndex = numbers.enumerated().first(where: { $0.element == frontStartIndex + 1 })?.offset {
    reverse(from: frontStartIndex, to: frontEndIndex)
    movedLog.append([frontStartIndex, frontEndIndex])
    solution(from: frontStartIndex, to: frontEndIndex)
    movedLog.removeLast()
    reverse(from: frontStartIndex, to: frontEndIndex)
  }
  if
    var backStartIndex = numbers.enumerated().reversed().first(where: { $0.element != $0.offset + 1})?.offset,
    var backEndIndex = numbers.enumerated().first(where: { $0.element == backStartIndex + 1 })?.offset {
    if backStartIndex > backEndIndex {
      swap(&backStartIndex, &backEndIndex)
    }
    
    reverse(from: backStartIndex, to: backEndIndex)
    movedLog.append([backStartIndex, backEndIndex])
    solution(from: backStartIndex, to: backEndIndex)
    movedLog.removeLast()
    reverse(from: backStartIndex, to: backEndIndex)
  }
}

func isAvailable(_ numbers: [Int]) -> Bool {
  let sortedNumbers = numbers.sorted()
  
  return sortedNumbers == numbers
}

func printAnswer() {
  while movedLog.count < 2 {
    movedLog.append([0, 0])
  }
  
  let answerString = movedLog.map { $0.map { "\($0 + 1)" }.joined(separator: " ") }
  
  answerString.forEach { print($0) }
}

func reverse(from index1: Int, to index2: Int) {
  var startIndex = index1
  let temp = index1 + index2

  while startIndex < temp - startIndex {
    let endIndex = temp - startIndex
    numbers.swapAt(startIndex, endIndex)
    startIndex += 1
  }
}

solution(from: 0, to: numbers.count - 1)
