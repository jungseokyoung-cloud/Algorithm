struct Position {
  let x: Int
  let y: Int
  
  init(_ x: Int, _ y: Int) {
    self.x = x
    self.y = y
  }
}

struct Queue<T> {
  private var elements = [T]()
  private var head = 0
  
  var isEmpty: Bool { head == elements.count }
  var count: Int { elements.count - head }
  
  mutating func enqueue(_ element: T) {
    elements.append(element)
  }
  
  mutating func dequeue() -> T? {
    guard !isEmpty else { return nil }
    defer { head += 1 }
    return elements[head]
  }
}

struct QueueItem {
  let position: Position
  let str: String
  
  init(_ position: Position, _ str: String) {
    self.position = position
    self.str = str
  }
}

var board = [String]()
var targets = [String: Int]()
var maxRow = 0
var maxCol = 0
let dx = [-1, -1, -1, 0, 1, 1, 1, 0]
let dy = [-1, 0, 1, 1, 1, 0, -1, -1]

func solution() {
  let (n, m, k) = readIntegers()
  maxRow = n
  maxCol = m
  
  board = configureBoard(n)
  let favorStrings = configureFavorStrings(k)
  
  for i in 0..<maxRow {
    for j in 0..<maxCol {
      bfs(x: i, y: j)
    }
  }
  
  let printStr = favorStrings.map { targets[$0] ?? 0 }
    .map { "\($0)" }
    .joined(separator: "\n")
  
  print(printStr)
}

func readIntegers() -> (Int, Int, Int) {
  let input = readLine()!.split(separator: " ").map { Int($0)! }
  return (input[0], input[1], input[2])
}

func configureBoard(_ n: Int) -> [String] {
  var board = [String]()
  for _ in 0..<n { board.append(readLine()!) }
  return board
}

func configureFavorStrings(_ k: Int) -> [String] {
  var strings = [String]()
  for _ in 0..<k { strings.append(readLine()!) }
  return strings
}

func bfs(x: Int, y: Int) {
  var queue = Queue<QueueItem>()
  queue.enqueue(.init(.init(x, y), board[x][y] ?? ""))
  
  while let item = queue.dequeue() {
    targets[item.str, default: 0] += 1
    guard item.str.count < 5 else { continue }
    
    for dis in 0..<8 {
      let nextPos = nextPosition(item.position.x + dx[dis], item.position.y + dy[dis])
      let temp = item.str + (board[nextPos.x][nextPos.y] ?? "")

      queue.enqueue(.init(nextPos, temp))
    }
  }
}

func nextPosition(_ x: Int, _ y: Int) -> Position {
  return .init(x < 0 ? maxRow - 1 : x % maxRow, y < 0 ? maxCol - 1 : y % maxCol)
}

solution()

extension String {
  subscript(index: Int) -> String? {
    guard index >= 0 && index < count else { return nil }
    
    let offset = self.index(self.startIndex, offsetBy: index)
    return String(self[offset])
  }
}
