struct CCTV {
  let type: Int
  var direction: Int
  let x: Int
  let y: Int
}

var map = [[Int]]()
var cctvs = [CCTV]()
var result = Int.max

let dirX = [-1, 0, 1, 0]
let dirY = [0, -1, 0, 1]

func solution() {
  let (n, _) = readPairIntegers()
  map = configureMap(col: n)
  cctvs = extractCCTV(from: map)
  configureMinBlindSpot(index: 0)
  print(result)
}

func configureMap(col: Int) -> [[Int]] {
  var map = Array(repeating: [Int](), count: col)
  
  for i in 0..<col {
    map[i].append(contentsOf: readIntegers())
  }
  
  return map
}

func extractCCTV(from map: [[Int]]) -> [CCTV] {
  var cctvs = [CCTV]()
  
  for i in 0..<map.count {
    for j in 0..<map[i].count {
      guard 1 <= map[i][j], map[i][j] <= 5 else { continue }
      
      cctvs.append(.init(type: map[i][j], direction: 0, x: i, y: j))
    }
  }
  
  return cctvs
}

func readPairIntegers() -> (Int, Int) {
  let inputs = readIntegers()
  return (inputs[0], inputs[1])
}

func readIntegers() -> [Int] {
  return readLine()!.split(separator: " ").compactMap { Int($0) }
}

func configureMinBlindSpot(index: Int) {
  guard index < cctvs.count else {
    result = min(result, getBlindSpot())
    return
  }
  
  for dir in 0..<4 {
    cctvs[index].direction = dir
    configureMinBlindSpot(index: index + 1)
    if cctvs[index].type == 5 { break }
  }
}

func getBlindSpot() -> Int {
  var tempMap = map
  
  for cctv in cctvs {
    let type = cctv.type
    
    if type == 1 {
      configureTempMap(x: cctv.x, y: cctv.y, direction: cctv.direction, tempMap: &tempMap)
    } else if type == 2 {
      configureTempMap(x: cctv.x, y: cctv.y, direction: cctv.direction, tempMap: &tempMap)
      configureTempMap(x: cctv.x, y: cctv.y, direction: (cctv.direction + 2) % 4, tempMap: &tempMap)
    } else if type == 3 {
      configureTempMap(x: cctv.x, y: cctv.y, direction: cctv.direction, tempMap: &tempMap)
      configureTempMap(x: cctv.x, y: cctv.y, direction: (cctv.direction + 1) % 4, tempMap: &tempMap)
    } else if type == 4 {
      configureTempMap(x: cctv.x, y: cctv.y, direction: cctv.direction, tempMap: &tempMap)
      configureTempMap(x: cctv.x, y: cctv.y, direction: (cctv.direction + 1) % 4, tempMap: &tempMap)
      configureTempMap(x: cctv.x, y: cctv.y, direction: (cctv.direction + 2) % 4, tempMap: &tempMap)
    } else {
      configureTempMap(x: cctv.x, y: cctv.y, direction: cctv.direction, tempMap: &tempMap)
      configureTempMap(x: cctv.x, y: cctv.y, direction: (cctv.direction + 1) % 4, tempMap: &tempMap)
      configureTempMap(x: cctv.x, y: cctv.y, direction: (cctv.direction + 2) % 4, tempMap: &tempMap)
      configureTempMap(x: cctv.x, y: cctv.y, direction: (cctv.direction + 3) % 4, tempMap: &tempMap)
    }
  }
  
  return tempMap.map { $0.filter { $0 == 0 }.count }.reduce(0, +)
}

func configureTempMap(x: Int, y: Int, direction: Int, tempMap: inout [[Int]]) {
  var currentX = x + dirX[direction]
  var currentY = y + dirY[direction]
  
  while true {
    guard currentX >= 0, currentX < tempMap.count, currentY >= 0, currentY < tempMap[0].count else { return }
    guard tempMap[currentX][currentY] != 6 else { return }
    
    tempMap[currentX][currentY] = -1
    
    currentX += dirX[direction]
    currentY += dirY[direction]
  }
}

solution()
