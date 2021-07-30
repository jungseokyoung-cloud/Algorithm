import Foundation

var n = Int(readLine()!)!

var array = readLine()!.split(separator: " ").map { Int(String($0))! }
array.sort()
print("\(array[0]) \(array.last!)")
