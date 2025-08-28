struct Queue<T> {
  private var elements = [T]()
  private var index = 0
  
  mutating func enqueue(_ element: T) {
    elements.append(element)
  }
  
  mutating func dequeue() -> T? {
    guard index < elements.count else { return nil }
    defer { index += 1 }
    return elements[index]
  }
}

func solution() {
  let _ = readInteger()
  let graph = configureGraph()
  var indegrees = configureIndegree(from: graph)
  var parents = [String: String]()
  var childs = [String: [String]]()
  var queue = Queue<String>()
  graph.forEach {
    parents[$0.key] = $0.key
    childs[$0.key] = []
  }
  
  indegrees.filter { $0.value == 0 }
    .forEach { queue.enqueue($0.key) }
  while let current = queue.dequeue() {
    guard let nextNames = graph[current] else { continue }
    
    nextNames.forEach {
      indegrees[$0]! -= 1
      if indegrees[$0] == 0 {
        queue.enqueue($0)
        parents[$0] = current
        childs[current]!.append($0)
      }
    }
  }
  
  var printValue = ""
  let roots = parents.filter { $0.key == $0.value }.keys
    .sorted()
  printValue = "\(roots.count)\n\(roots.joined(separator: " "))"
  
  childs.sorted { $0.key < $1.key }.forEach {
    printValue += "\n\($0.key) \($0.value.count) \($0.value.sorted().joined(separator: " "))"
  }
  
  print(printValue)
}

func configureGraph() -> [String: [String]] {
  let currentNames = readStrings()
  let informationCount = readInteger()
  
  var graph = [String: [String]]()
  currentNames.forEach { graph[$0] = [] }
  
  for _ in 0..<informationCount {
    let inputs = readStrings()
    graph[inputs[1]]?.append(inputs[0])
  }
  
  return graph
}

func configureIndegree(from graph: [String: [String]]) -> [String: Int] {
  var indegrees = [String: Int]()
  graph.keys.forEach { indegrees[$0] = 0 }
  
  graph.forEach {
    $0.value.forEach { indegrees[$0, default: 0] += 1 }
  }

  return indegrees
}

func readInteger() -> Int {
  return Int(readLine()!)!
}

func readStrings() -> [String] {
  return readLine()!.split(separator: " ").map { String($0) }
}

solution()
