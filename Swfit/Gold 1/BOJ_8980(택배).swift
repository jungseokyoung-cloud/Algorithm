struct Delivery {
  let source: Int
  let destination: Int
  let capacity: Int
}

func solution() {
  let (beliegeCount, capacity) = readPairIntegers()
  let deliveryCount = readInteger()
  let deliveries = configureDelieveries(deliveryCount)
  let sortedDeliveries = deliveries.sorted {
    $0.destination == $1.destination ? $0.source > $1.source : $0.destination < $1.destination
  }
  
  var totalCost = 0
  var costInfo = Array(repeating: 0, count: beliegeCount + 1)
  
  for delivery in sortedDeliveries {
    let minRemain = costInfo[delivery.source..<delivery.destination]
      .map { capacity - $0 }.min() ?? 0
    
    let cost = min(minRemain, delivery.capacity)
    guard cost != 0 else { continue }
    totalCost += cost
    (delivery.source..<delivery.destination).forEach { costInfo[$0] += cost }
  }
  
  print(totalCost)
}

func configureDelieveries(_ count: Int) -> [Delivery] {
  var deliveries: [Delivery] = []
  for _ in 0..<count {
    deliveries.append(readDelievery())
  }
  return deliveries
}

func readPairIntegers() -> (Int, Int) {
  let inputs = readLine()!.split(separator: " ").map { Int($0)! }
  return (inputs[0], inputs[1])
}

func readInteger() -> Int {
  return Int(readLine()!)!
}

func readDelievery() -> Delivery {
  let inputs = readLine()!.split(separator: " ").map { Int($0)! }
  
  return .init(source: inputs[0], destination: inputs[1], capacity: inputs[2])
}

solution()
