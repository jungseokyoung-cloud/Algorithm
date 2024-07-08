//
//  BOJ_7570(줄 세우기).swift
//  BOJ2
//
//  Created by jung on 7/8/24.
//

func solution() {
	let n = readInterger()
	let array = readIntergers()
	var dp = Array(repeating: 0, count: n+1)
	var result = 0
	
	for element in array {
		dp[element] = dp[element-1] + 1
		result = max(result, dp[element])
	}
	
	print(n - result)
}

func readInterger() -> Int {
	return Int(readLine()!)!
}

func readIntergers() -> [Int] {
	return readLine()!.split(separator: " ").map { Int($0)! }
}

solution()
