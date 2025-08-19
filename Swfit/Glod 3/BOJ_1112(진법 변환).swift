func solution() {
  let (number, radix) = readPairInteger()
  let radixNumber = convertBase(number, radix: radix)
  print(radixNumber)
}

func readPairInteger() -> (Int, Int) {
  let inputs = readLine()!.split(separator: " ").map { Int($0)! }
  
  return (inputs[0], inputs[1])
}

func convertBase(_ number: Int, radix: Int) -> String {
  guard number != 0 else { return "0" }
  if radix > 0, number < 0 { return "-\(convertBase(-number, radix: radix))" }

  var current = number
  let nonNegativeRadix = abs(radix)
  var out = ""
  
  
  while current != 0 {
    var remainder = current % nonNegativeRadix
    if remainder < 0 { remainder += nonNegativeRadix }
    out += String(remainder)
    
    current = radix < 0 ? (current - remainder) / radix : current / radix
  }
  
  return String(out.reversed())
}

//solution()
print(convertBase(-52, radix: -2))
print(convertBase(-38, radix: 4))
