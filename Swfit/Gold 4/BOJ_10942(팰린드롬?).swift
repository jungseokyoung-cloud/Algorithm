import Foundation

class FileIO {
  @inline(__always) private var buffer: [UInt8] = Array(FileHandle.standardInput.readDataToEndOfFile()) + [0], byteIdx = 0
  
  @inline(__always) private func readByte() -> UInt8 {
    defer { byteIdx += 1 }
    return buffer.withUnsafeBufferPointer { $0[byteIdx] }
  }
  
  @inline(__always) func readInt() -> Int {
    var number = 0, byte = readByte(), isNegative = false
    while byte == 10 || byte == 32 { byte = readByte() }
    if byte == 45 { byte = readByte(); isNegative = true }
    while 48...57 ~= byte { number = number * 10 + Int(byte - 48); byte = readByte() }
    return number * (isNegative ? -1 : 1)
  }
  
  @inline(__always) func readStirngSum() -> Int {
    var byte = readByte()
    while byte == 10 || byte == 32 { byte = readByte() }
    var sum = Int(byte)
    while byte != 10 && byte != 32 && byte != 0 { byte = readByte(); sum += Int(byte) }
    return sum - Int(byte)
  }
  
  @inline(__always) private func write(_ output: String) {
    FileHandle.standardOutput.write(output.data(using: .utf8)!)
  }
}

enum PalindromeType {
  case none
  case isPalindrome
  case notPalindrome
  
  init(_ result: Bool) {
    self = result ? .isPalindrome : .notPalindrome
  }
}

var numbers = [Int]()
var isPalindrome = [[PalindromeType]]()

func solution() {
  let fileIO = FileIO()
  let n = fileIO.readInt()
  numbers = readIntegers(fileIO, count: n).map { $0 - 1 }
  
  let testCount = fileIO.readInt()
  var resultString = ""
  configureIsPalindrome(count: n)
  (0..<testCount).forEach { _ in
    let (start, end) = readPairIntegers(fileIO)
    let result = isPalineDromAt(start - 1, between: end - 1)
    resultString += result ? "1\n" : "0\n"
  }
  
  print(resultString)
}

func readPairIntegers(_ fileIO: FileIO) -> (Int, Int) {
  let input1 = fileIO.readInt()
  let input2 = fileIO.readInt()
  
  return (input1, input2)
}

func readIntegers(_ fileIO: FileIO, count: Int) -> [Int] {
  var integers: [Int] = []
  (0..<count).forEach { _ in integers.append(fileIO.readInt()) }
  return integers
}

func configureIsPalindrome(count: Int) {
  isPalindrome = Array(
    repeating: Array(repeating: .none, count: count),
    count: count
  )
  
  for i in 0..<count { isPalindrome[i][i] = .isPalindrome }
}

func isPalineDromAt(_ startIndex: Int, between endIndex: Int) -> Bool {
  guard startIndex < endIndex else { return true }
  
  guard isPalindrome[startIndex][endIndex] == .none else {
    return isPalindrome[startIndex][endIndex] == .isPalindrome
  }
  
  var result: Bool
  
  if numbers[startIndex] != numbers[endIndex] {
    result = false
  } else {
    result = isPalineDromAt(startIndex + 1, between: endIndex - 1)
  }
  
  isPalindrome[startIndex][endIndex] = .init(result)
  
  return result
}

solution()
