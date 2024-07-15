//
//  BOJ_2504(괄호의 값).swift
//  BOJ2
//
//  Created by jung on 7/15/24.
//

func solution() -> Int {
	let str = readLine()!
	var stack = [Character]()
	var total = 0
	var temp = 1
	var lastOpend = true
	
	for char in str {
		if char == "(" {
			temp *= 2
			stack.append("(")
			lastOpend = true
		} else if char == "[" {
			temp *= 3
			stack.append("[")
			lastOpend = true
		} else if char == ")", let top = stack.last, top == "(" {
			stack.removeLast()
			if lastOpend { total += temp }
			temp /= 2
			lastOpend = false
			
		} else if char == "]", let top = stack.last, top == "[" {
			stack.removeLast()
			if lastOpend { total += temp }
			temp /= 3
			lastOpend = false
		} else {
			return 0
		}
	}
	
	return stack.isEmpty ? total : 0
}

print(solution())

