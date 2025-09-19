struct Queue<T> {
  private var elements = [T]()
  private var index = 0
  
  var count: Int { elements.count - index }
  var isEmpty: Bool { count == 0 }
  
  mutating func enqueue(_ element: T) {
    elements.append(element)
  }
  
  mutating func dequeue() -> T? {
    guard !isEmpty else { return nil }
    defer { index += 1 }
    return elements[index]
  }
}

var map = [[String]]()
var temp = [Int]()
var answer = 0
let dx = [-1, 0, 1, 0]
let dy = [0, -1, 0, 1]

func solution(_ tempMap: [[String]]) -> Int {
  map = tempMap

  configureCandidates(0)
  
  return answer
}

func configureCandidates(_ current: Int) {
  if temp.count == 7, isConnected(temp) {
    answer += 1
    return
  }
  
  guard current < 25 else { return }
  if current > 25 - (7 - temp.count) { return }
  
  for next in current..<25 {
    temp.append(next)
    configureCandidates(next + 1)
    temp.removeLast()
  }
}

func isConnected(_ values: [Int]) -> Bool {
  let points: [(Int, Int)] = values.map { ($0 / 5, $0 % 5) }
  let cnt = points.filter { map[$0.0][$0.1] == "S" }.count
  
  guard cnt >= 4 else { return false }
  
  var isVised = Array(repeating: false, count: 7)
  var queue = Queue<(Int, Int)>()
  isVised[0] = true
  queue.enqueue(points[0])
  
  while let current = queue.dequeue() {
    for dis in 0..<4 {
      let nx = current.0 + dx[dis]
      let ny = current.1 + dy[dis]
      
      guard nx >= 0, nx < 5, ny >= 0, ny < 5 else { continue }
      let nextIndex = points.enumerated()
        .first { $0.1.0 == nx && $0.1.1 == ny }?.offset
      
      guard let nextIndex = nextIndex else { continue }
      guard !isVised[nextIndex] else { continue }
      queue.enqueue(points[nextIndex])
      isVised[nextIndex] = true
    }
  }

  return isVised.filter { !$0 }.isEmpty
}

var inputs = [[String]]()

for _ in 0..<5 {
  let temp = readLine()!.map { String($0) }
  inputs.append(temp)
}

let result = solution(inputs)
print(result)
