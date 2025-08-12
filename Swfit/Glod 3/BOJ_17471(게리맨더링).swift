struct Queue<T> {
  private var elements = [T]()
  private var index = 0
  
  var isEmpty: Bool { elements.count == index }
  var count: Int { elements.count - index }
  
  mutating func enqueue(_ element: T) {
    elements.append(element)
  }
  
  mutating func dequeue() -> T? {
    guard !isEmpty else { return nil }
    defer { index += 1 }
    return elements[index]
  }
}

var cityPopulation = [Int]()
var map = [[Int]]()
var answer = Int.max
var aCities = [Int]()
var totalScore = 0

func solution() {
  let cityCount = readInteger()
  cityPopulation = readIntegers()
  map = configureMap(cityCount)
  
  totalScore = cityPopulation.reduce(0, +)
  
  splitIntoTwoCities(cityNumber: 0)
  
  print(answer == Int.max ? -1 : answer)
}

func readInteger() -> Int {
  return Int(readLine()!)!
}

func configureMap(_ cityCount: Int) -> [[Int]] {
  var map = Array(repeating: [Int](), count: cityCount)
  
  for i in 0..<cityCount {
    let inputs = readIntegers()
    guard inputs[0] != 0 else { continue }
    let cities = inputs[1..<inputs.count].map { $0 - 1 }
    
    map[i].append(contentsOf: cities)
  }
  
  return map
}

func readIntegers() -> [Int] {
  return readLine()!.split(separator: " ").compactMap { Int($0) }
}

func splitIntoTwoCities(cityNumber: Int) {
  if cityNumber == map.count {
    let score = getScore(cities: aCities)
    answer = min(score, answer)
    return
  }
  
  // 추가 X
  splitIntoTwoCities(cityNumber: cityNumber + 1)
  
  // 추가
  aCities.append(cityNumber)
  splitIntoTwoCities(cityNumber: cityNumber + 1)
  
  // 후처리
  aCities.removeLast()
}

func getScore(cities: [Int]) -> Int {
  let bCities = (0..<map.count).filter { !cities.contains($0) }
  let bCityScores = bCities.map { cityPopulation[$0] }.reduce(0, +)
  
  return isConnected(aCities) && isConnected(bCities) ? abs(totalScore - 2 * bCityScores) : Int.max
}

func isConnected(_ cities: [Int]) -> Bool {
  guard !cities.isEmpty else { return false }
  
  var visCount = 0
  var queue = Queue<Int>()
  
  var isVis = Array(repeating: -1, count: map.count)
  cities.forEach { isVis[$0] = 0 }
  
  isVis[cities[0]] = 1
  queue.enqueue(cities[0])
  visCount += 1
  
  while let current = queue.dequeue() {
    let candidates = map[current].filter { isVis[$0] == 0 }
    
    candidates.forEach {
      isVis[$0] = 1
      queue.enqueue($0)
      visCount += 1
    }
  }
  
  return visCount == cities.count
}

solution()
