import Foundation

func findNext(_ now : Int) -> Int {
    var add = now%10
    add += now/10
    add%=10
    var next : String = String()
    next.append(String(now%10))
    next.append(String(add))
    return Int(next)!
}


var n = Int(readLine()!)!

if n < 10 {
    n *= 10
}

var ans = 1
if n != 0 {
    var next = findNext(n)
    while n != next {
        ans+=1
        next = findNext(next)
    }

}
print(ans)
