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

struct Position {
  let x: Int
  let y: Int
  
  init(_ x: Int, _ y: Int) {
    self.x = x
    self.y = y
  }
}

fileprivate let dx = [-1, 0, 1, 0]
fileprivate let dy = [0, 1, 0, -1]
fileprivate var isVis = [[Int]]()
fileprivate var queues = [Queue<Position>]()
fileprivate var playerScores = [Int]()
fileprivate var moveCounts: [Int] = []
fileprivate var map = [[Int]]()

func solution() {
  let (col, _, playerCount) = readTupleIntegers()
  moveCounts = readIntegers()
  configureMap(col)
  configureInitialPosition(playerCount: playerCount)
  play(playerCount: playerCount)

  print(playerScores[1...playerCount].map { "\($0)" }.joined(separator: " "))
}

func configureMap(_ col: Int) {
  map = Array(repeating: [Int](), count: col)
  
  for i in 0..<col {
    let inputs = readLine()!
  
    let temp = inputs.map { char -> Int in
      if char == "." {
        return 0
      } else if char == "#" {
        return -1
      } else {
        return Int(String(char))!
      }
    }
    
    map[i] = temp
  }
}

func readTupleIntegers() -> (Int, Int, Int) {
  let inputs = readIntegers()
  
  return (inputs[0], inputs[1], inputs[2])
}

func readIntegers() -> [Int] {
  return readLine()!.split(separator: " ").map { Int($0)! }
}

func configureInitialPosition(playerCount: Int) {
  isVis = Array(repeating: Array(repeating: -1, count: map[0].count), count: map.count)
  queues = Array(repeating: Queue<Position>(), count: playerCount + 1)
  playerScores = Array(repeating: 0, count: playerCount + 1)
  
  for i in 0..<map.count {
    for j in 0..<map[0].count {
      guard map[i][j] >= 1 else { continue }
      let player = map[i][j]
      queues[player].enqueue(Position(i, j))
      isVis[i][j] = 0
      playerScores[player] += 1
    }
  }
}

func play(playerCount: Int) {
  var isChanged = true
  
  while isChanged {
    isChanged = false
    
    for player in 1...playerCount {
      guard let top = queues[player].front else { continue }
      let maxMoveCnt = moveCounts[player - 1]
      let initialValue = isVis[top.x][top.y]
      
      while let top = queues[player].front {
        let cnt = isVis[top.x][top.y]
        
        guard cnt - initialValue != maxMoveCnt else { break }
        queues[player].dequeue()
        for dis in 0..<4 {
          let nx = top.x + dx[dis]
          let ny = top.y + dy[dis]
          
          guard nx >= 0, nx < map.count, ny >= 0, ny < map[0].count else { continue }
          guard isVis[nx][ny] == -1, map[nx][ny] == 0 else { continue }
          
          isVis[nx][ny] = cnt + 1
          queues[player].enqueue(.init(nx, ny))
          playerScores[player] += 1
          isChanged = true
        }
      }
    }
  }
}

solution()

