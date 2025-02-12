func solution() {
  let width = Int(readLine()!)!
  let result = availableTileCount(width)
  print(result)
}

func availableTileCount(_ width: Int) -> Int {
  guard width >= 2 else { return 0 }
  
  var results = Array(repeating: 0, count: width + 1)
  results[0] = 1
  for current in 2...width {
    guard current % 2 == 0 else { continue }
    
    results[current] += results[current - 2] * 3
    var temp = current - 4
    while temp >= 0 {
      results[current] += results[temp] * 2
      temp -= 2
    }
  }
  
  return results[width]
}

solution()
