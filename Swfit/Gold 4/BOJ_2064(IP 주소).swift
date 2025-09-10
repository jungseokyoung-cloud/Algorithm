func solution() {
  let cnt = readInteger()
  let ipAddress = configureIPAddress(cnt)
  let (networkAddress, networkMask) = getNetworkAddress(ipAddress)
  
  print(convertToIPAddress(networkAddress))
  print(convertToIPAddress(networkMask))
}

func readInteger() -> Int {
  return Int(readLine()!)!
}

func configureIPAddress(_ cnt: Int) -> [Int] {
  var ipAddress = Array(repeating: 0, count: cnt)
  
  for i in 0..<cnt {
    let inputs = readLine()!.split(separator: ".").map { Int($0)! }
    
    inputs.forEach {
      ipAddress[i] = (ipAddress[i] << 8) | $0
    }
  }
  
  return ipAddress
}

func getNetworkAddress(_ ipAddress: [Int]) -> (Int, Int) {
  var networkAddress = ipAddress[0]
  var networkMask = 0xffffffff

  guard ipAddress.count > 1 else { return (networkAddress, networkMask) }
  
  for i in 1..<ipAddress.count {
    let networkBit = ipAddress[i] & networkMask // 맥시멈 networkBit
    let diff = networkBit ^ networkAddress // 둘 간의 차이
    
    networkAddress = 0
    var newNetworkMask = 0
    var isEndNetworkBit = false
    
    for bit in stride(from: 31, through: 0, by: -1) {
      if diff & (1 << bit) > 0 || networkMask & (1 << bit) == 0 { isEndNetworkBit = true }
      
      networkAddress = networkAddress << 1
      newNetworkMask = newNetworkMask << 1
      
      guard !isEndNetworkBit else { continue }
      
      networkAddress |= (networkBit >> bit) & 1
      newNetworkMask |= 1
    }
    
    networkMask = newNetworkMask
  }
  
  return (networkAddress, networkMask)
}

func convertToIPAddress(_ networkAddress: Int) -> String {
  var results: [String] = []
  
  var networkAddress = networkAddress
  
  for _ in 0..<4 {
    let temp = networkAddress & 0xff
    results.append(String(temp))
    networkAddress = networkAddress >> 8
  }
  
  return results.reversed().joined(separator: ".")
}

solution()
