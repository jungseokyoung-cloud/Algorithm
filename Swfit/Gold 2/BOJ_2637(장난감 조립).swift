struct ToyPart {
  let partId: Int
  let count: Int
  
  init(_ partId: Int, _ count: Int) {
    self.partId = partId
    self.count = count
  }
}

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

func solution() {
  let toypartsCount = readInteger()
  let m = readInteger()
  let toyPartMap = configureToyPartsMap(toypartCount: toypartsCount, m)
  let basicParts = configureBasicParts(toyPartMap)
  var indegrees = configureIndegrees(toyPartMap)
  var partCounts = Array(repeating: 0, count: toypartsCount + 1)
  var queue = Queue<Int>()
  
  partCounts[toypartsCount] = 1
  
  indegrees.enumerated()
    .filter { $0.element == 0 }
    .map { $0.offset }
    .filter { $0 != 0 }
    .forEach { queue.enqueue($0) }

  while let current = queue.dequeue() {
    let count = partCounts[current]
    guard count != 0 else { continue }
    
    for next in toyPartMap[current] {
      indegrees[next.partId] -= 1
      partCounts[next.partId] += count * next.count
      
      if indegrees[next.partId] == 0 { queue.enqueue(next.partId) }
    }
  }
  
  let output = partCounts.enumerated()
    .filter { basicParts.contains($0.offset) }
    .map { "\($0.offset) \($0.element)" }
    .joined(separator: "\n")
  
  print(output)
}

func configureToyPartsMap(toypartCount: Int, _ m: Int) -> [[ToyPart]] {
  var toyPartsMap = Array(repeating: [ToyPart](), count: toypartCount + 1)
  
  (0..<m).forEach { _ in
    let (x, y, k) = readTupleInteger()
    toyPartsMap[x].append(.init(y, k))
  }
  
  return toyPartsMap
}

func configureIndegrees(_ toyPartsMap: [[ToyPart]]) -> [Int] {
  var indegrees = Array(repeating: 0, count: toyPartsMap.count)
  
  for map in toyPartsMap {
    map.forEach { indegrees[$0.partId] += 1 }
  }
  
  return indegrees
}

func configureBasicParts(_ toyPartsMap: [[ToyPart]]) -> [Int] {
  var outdegrees = Array(repeating: 0, count: toyPartsMap.count)
  
  for (index, map) in toyPartsMap.enumerated() {
    outdegrees[index] += map.count
  }
  
  return outdegrees.enumerated()
    .filter { $0.element == 0 }
    .map { $0.offset }
    .filter { $0 != 0 }
}

func readInteger() -> Int {
  return Int(readLine()!)!
}

func readTupleInteger() -> (Int, Int, Int) {
  let inputs = readLine()!.split(separator: " ").compactMap { Int($0) }
  
  return (inputs[0], inputs[1], inputs[2])
}

solution()
