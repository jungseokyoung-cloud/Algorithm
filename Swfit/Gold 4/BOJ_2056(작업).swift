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

struct TaskType {
  var time: Int
  var predecessors: [Int]
  
  init(_ time: Int, _ predecessors: [Int]) {
    self.time = time
    self.predecessors = predecessors
  }
}

func solution() {
  let taskCount = readInteger()
  let taskMap = configureTaskMap(taskCount: taskCount)
  var indegrees = configureIndegrees(taskMap)
  var queue = Queue<Int>()
  var times = Array(repeating: 0, count: taskCount)
  var total = 0
  indegrees.enumerated().filter { $1 == 0 }.forEach {
    queue.enqueue($0.offset)
    times[$0.offset] = taskMap[$0.offset].time
  }
  
  while let current = queue.dequeue() {
    total = max(total, times[current])
    taskMap[current].predecessors.forEach {
      let totalTime = times[current] + taskMap[$0].time
      indegrees[$0] -= 1
      times[$0] = max(times[$0], totalTime)
      
      if indegrees[$0] == 0 { queue.enqueue($0) }
    }
  }
  
  print(total)
}

func configureTaskMap(taskCount: Int) -> [TaskType] {
  var taskMap = Array(repeating: TaskType(0, []), count: taskCount)
  
  for index in 0..<taskCount {
    let inputs = readIntegers()
    let time = inputs[0]
    let predecessorCount = inputs[1]
    taskMap[index].time = time
    guard predecessorCount > 0 else { continue }
    
    for prodecessor in inputs[2..<inputs.count] {
      taskMap[prodecessor - 1].predecessors.append(index)
    }
  }
  
  return taskMap
}

func configureIndegrees(_ taskMap: [TaskType]) -> [Int] {
  var indegrees = Array(repeating: 0, count: taskMap.count)
  
  for task in taskMap {
    task.predecessors.forEach { indegrees[$0] += 1 }
  }
  
  return indegrees
}

func readInteger() -> Int {
  return Int(readLine()!)!
}

func readIntegers() -> [Int] {
  return readLine()!.split(separator: " ").map { Int($0)! }
}

solution()
