import Foundation

func findAns(_ num : Int) -> Bool {
    var temp = num
    let diff = temp%10 - (temp/10)%10
    temp/=10
    while temp >= 10 {
        let comp = temp%10 - (temp/10)%10
        temp/=10
        if comp != diff {
            return false
        }
    }
    return true
}

var n = Int(readLine()!)!
var ans = 0
for i in 1...n {
    if i < 100 {
        ans+=1
    } else {
        let res = findAns(i)
        if res == true {
            ans+=1
        }
    }
}
print(ans)
