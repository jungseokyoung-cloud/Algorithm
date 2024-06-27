//
//  BOJ_2482(색상환).swift
//  BOJ2
//
//  Created by jung on 6/24/24.
//

import Foundation

func solution() {
	let n = readInterger()
	let k = readInterger()
	let mod = 1000000003
	var dp = Array(
		repeating: Array(repeating: 0, count: k+1),
		count: n
	)
	
	dp[1][0] = 1
	dp[1][1] = 1
	
	for col in (2..<dp.count) {
		dp[col][0] = 1
		dp[col][1] = col
		
		for row in (2..<dp[col].count) {
			dp[col][row] = (dp[col-1][row] + dp[col-2][row-1]) % mod
		}
	}
	
	print((dp[n-1][k] + dp[n-3][k-1]) % mod)
}

func readInterger() -> Int {
	return Int(readLine()!)!
}

solution()
