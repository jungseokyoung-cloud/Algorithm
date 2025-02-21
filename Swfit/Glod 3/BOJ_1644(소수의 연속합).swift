func solution() {
  let number = Int(readLine()!)!
  let result = consecutivePrimesCount(number)
  print(result)
}

func consecutivePrimesCount(_ number: Int) -> Int {
  let primes = primNumbers(until: number)

  guard !primes.isEmpty else { return 0 }
  
  var result = 0
  var en = 1
  var temp = primes[0]
  
  for st in 0..<primes.count {

    while en < primes.count && temp + primes[en] <= number {
      temp += primes[en]
      en += 1
    }
    
    if temp == number { result += 1 }
    
    temp -= primes[st]
  }
  
  return result
}

func primNumbers(until num: Int) -> [Int] {
  var isPrime = Array(repeating: true, count: num + 1)
  
  isPrime[0] = false
  isPrime[1] = false
  var temp = 2
  
  while temp * temp <= num {
    defer { temp += 1 }
    
    guard isPrime[temp] else { continue }
    
    for i in stride(from: temp * temp, to: num + 1, by: temp) {
      isPrime[i] = false
    }
  }
  
  return isPrime.enumerated().filter { $0.element }.map { $0.offset }
}

solution()
