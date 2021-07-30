import Foundation

var t = Int(readLine()!)!
for _ in 1...t {
//    var array : [Int] = []
//    let array = (readLine()?.split(separator: " ").map {Int($0)!})!
    let array = readLine()!.split(separator: " ").map {Int($0)!}

    print(array[0] + array[1])
}
