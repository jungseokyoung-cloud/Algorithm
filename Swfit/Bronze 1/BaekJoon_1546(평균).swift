import Foundation

let n = Float(readLine()!)!

var array : [Float] = (readLine()!.split(separator: " ")).map { Float($0)! }

var max : Float = 0

for a in array {
    if max < a{
        max = a
    }
}
var averrage : Float = 0
for a in array {
    averrage += (a/max*100)
}

print(averrage/n)

