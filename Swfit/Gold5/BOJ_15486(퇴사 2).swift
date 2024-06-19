//
//  BOJ_15486(퇴사 2).swift
//  BOJ2
//
//  Created by jung on 6/19/24.
//

import Foundation

struct Info {
	let time: Int
	let payment: Int
}

func solution() {
	let n = readInteger()
	var informations = [Info]()
	var results = Array(repeating: 0, count: n+1)
	
	for _ in (0..<n) {
		let info = readIntegers()
		
		informations.append(Info(time: info[0], payment: info[1]))
	}
	
	for (index, information) in informations.enumerated() {
		let next = index + information.time
		
		if index > 0 {
			results[index] = max(results[index], results[index - 1])
		}
		
		if next > n { continue }

		results[next] = max(results[next], results[index] + information.payment)
	}
	
	print(results.max() ?? 0)
}

func readInteger() -> Int {
	return Int(readLine()!)!
}

func readIntegers() -> [Int] {
	return readLine()!.split(separator: " ").map { Int($0)! }
}

solution()
