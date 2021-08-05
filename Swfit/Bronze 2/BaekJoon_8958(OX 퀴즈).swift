//
//  main.swift
//  Swift(Practice)
//
//  Created by jung on 2021/07/28.
//

import Foundation
var t = Int(readLine()!)!
for _ in 1...t {
    let s : String = readLine()!
    var add : Int = 1
    var ans : Int = 0
    for num in s {
        
        if num == "O" {
            ans += add
            add+=1
        } else {
            add = 1
        }
    }
    print(ans)
}

