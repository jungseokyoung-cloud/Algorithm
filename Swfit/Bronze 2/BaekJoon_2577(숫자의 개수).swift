import Foundation

var array = [Int](repeating: 0, count: 10)

var a = Int(readLine()!)!
var b = Int(readLine()!)!
var c = Int(readLine()!)!

var result = a * b * c

while result != 0 {
    let idx = result % 10
    array[idx] += 1
    result /= 10
}

for idx in 0...9 {
    print(array[idx])
}
