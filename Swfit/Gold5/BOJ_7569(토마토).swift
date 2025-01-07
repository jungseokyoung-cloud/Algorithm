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
  let inputs = readLine()!.split(separator: " ").map { Int($0)! }
  let board = configureBoard(
    xCount: inputs[0],
    yCount: inputs[1],
    zCount: inputs[2]
  )
  
  let result = runBoard(
    board,
    xCount: inputs[0],
    yCount: inputs[1],
    zCount: inputs[2]
  )
  
  print(result)
}

func configureBoard(xCount: Int, yCount: Int, zCount: Int) -> [[[Int]]] {
  var board = Array(
    repeating: Array(
      repeating: Array(repeating: 0, count: xCount),
      count: yCount
    ),
    count: zCount
  )
  
  
  for z in 0..<zCount {
    for y in 0..<yCount {
      let inputs = readLine()!.split(separator: " ").map { Int($0)! }
      
      for (x, value) in inputs.enumerated() {
        board[z][y][x] = value
      }
    }
  }
  
  return board
}

func runBoard(
  _ board: [[[Int]]],
  xCount: Int,
  yCount: Int,
  zCount: Int
) -> Int {
  let dx = [0, 0, 1, 0, 0, -1]
  let dy = [0, -1, 0, 0, 1, 0]
  let dz = [-1, 0, 0, 1, 0, 0]
  var isVis = Array(
    repeating: Array(
      repeating: Array(repeating: -1, count: xCount),
      count: yCount
    ),
    count: zCount
  )
  var queue = Queue<(Int, Int, Int)>()
  
  for z in 0..<zCount {
    for y in 0..<yCount {
      for x in 0..<xCount {
        guard board[z][y][x] == 1 else { continue }
        isVis[z][y][x] = 0
        queue.enqueue((z, y, x))
      }
    }
  }
  
  while let top = queue.front {
    queue.dequeue()
    let value = isVis[top.0][top.1][top.2]
    for dis in 0..<6 {
      let nz = top.0 + dz[dis]
      let ny = top.1 + dy[dis]
      let nx = top.2 + dx[dis]
      
      guard nz >= 0 && nz < zCount && ny >= 0 && ny < yCount && nx >= 0 && nx < xCount else { continue }
      guard isVis[nz][ny][nx] == -1 else { continue }
      guard board[nz][ny][nx] == 0 else { continue }
      isVis[nz][ny][nx] = value + 1
      queue.enqueue((nz, ny, nx))
    }
  }
    
  var maxValue = -1
  for z in 0..<zCount {
    for y in 0..<yCount {
      for x in 0..<xCount {
        
        if board[z][y][x] == 0 && isVis[z][y][x] == -1 { return -1 }
        maxValue = max(maxValue, isVis[z][y][x])
      }
    }
  }
  
  return maxValue
}

solution()
