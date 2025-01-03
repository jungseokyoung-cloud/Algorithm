// MARK: - Data Structure
struct Queue<T> {
  private var elements: [T] = []
  private var head: Int = 0

  var count: Int { elements.count - head }
  var isEmpty: Bool { count == 0 }
  var front: T? {
    guard !isEmpty else { return nil }
    return elements[head]
  }
}

// MARK: - Methods
extension Queue {
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

enum TaggerMoveType: CaseIterable {
  case forward
  case back
  case teleport
}

let maxPoint = 500000

func solution() {
  let inputs = readLine()!.split(separator: " ").map { Int($0)! }
  
  let result = getMinTime(taggerPoint: inputs[0], runnerPoint: inputs[1])
  print(result)
}

func getMinTime(taggerPoint: Int, runnerPoint: Int) -> Int {
  var arriveTimes = Array(
    repeating: Array(repeating: -1, count: 2),
    count: maxPoint + 1
  )
  
  var queue = Queue<(Int, Int, Int)>() // tagger위치, runner위치, 이동 거리
  queue.enqueue((taggerPoint, runnerPoint, 0))
  arriveTimes[taggerPoint][0] = 0
  
  while let front = queue.front {
    queue.dequeue()
    
    guard front.1 <= maxPoint else { break }

    if arriveTimes[front.1][index(from: front.2)] != -1 { return front.2 }

    TaggerMoveType.allCases.forEach {
      let next = taggeerMove(from: front.0, moveType: $0)
      let cnt = front.2 + 1
      let index = index(from: cnt)
      
      guard next >= 0 && next <= maxPoint else { return }
      guard arriveTimes[next][index] == -1 else { return }

      arriveTimes[next][index] = cnt
      
      queue.enqueue((next, front.1 + cnt, cnt))
    }
  }
    
  return -1
}

func taggeerMove(from point: Int, moveType: TaggerMoveType) -> Int {
  switch moveType {
    case .forward:
      return point + 1
    case .back:
      return point - 1
    case .teleport:
      return point * 2
  }
}

func index(from count: Int) -> Int {
  return count.isEven ? 0 : 1
}

extension Int {
  var isEven: Bool {
    self % 2 == 0
  }
}

solution()
