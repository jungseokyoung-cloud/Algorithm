struct Queue<T> {
  private var elements = [T]()
  private var head = 0
  
  var count: Int { elements.count - head }
  var isEmpty: Bool { count == 0 }
  var front: T? {
    guard !isEmpty else { return nil }
    return elements[head]
  }
  
  mutating func enqueue(_ element: T) {
    elements.append(element)
  }
  
  @discardableResult
  mutating func dequeue() -> T? {
    guard !isEmpty else { return nil }
    defer { head += 1 }
    return elements[head]
  }
}

func solution() {
  let n = readInteger()
  let _ = readInteger()
  let tempPasswords = readIntegers()
  
  var result = 0
  var queue = Queue<(Int, Int)>()
  var isVis = Array(repeating: -1, count: n + 1)
  tempPasswords.forEach {
    queue.enqueue(($0, 0))
    isVis[$0] = 0
  }
  
  while let top = queue.dequeue() {
    let current = top.0
    let cnt = top.1
    
    result = max(result, cnt)
    for shift in 0...20 {
      let next = (1<<shift) ^ current
      guard next <= n, isVis[next] == -1 else { continue }
      isVis[next] = cnt + 1
      queue.enqueue((next, cnt + 1))
    }
  }
  
  print(result)
}

func readInteger() -> Int {
  return Int(readLine()!)!
}

func readIntegers() -> [Int] {
  return readLine()!.split(separator: " ").map { Int($0)! }
}

solution()
