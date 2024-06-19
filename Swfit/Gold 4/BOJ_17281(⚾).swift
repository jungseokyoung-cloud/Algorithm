//
//  BOJ_17281(⚾).swift
//  BOJ2
//
//  Created by jung on 6/19/24.
//

import Foundation

func solution() {
	let n = readInteger()
	var teamInformations: [[Int]] = []
	
	for _ in (0..<n) {
		teamInformations.append(readIntergers())
	}
	
	let isSelelected = Array(repeating: false, count: 9)
	let battingOrder = [Int]()
	
	let result = getMaximumScore(inningCount: n, isSelected: isSelelected, battingOrder: battingOrder, teamInformations: teamInformations)
	
	print(result)
}

func getMaximumScore(
	inningCount: Int,
	isSelected: [Bool],
	battingOrder: [Int],
	teamInformations: [[Int]]
) -> Int {
	guard battingOrder.count != 9 else {
		return getScore(inningCount: inningCount, battingOrder: battingOrder, teamInformations: teamInformations)
	}
	
	var _isSelected = isSelected
	var _battingOrder = battingOrder
	var maxScore = 0
	
	if battingOrder.count == 3 {
		_battingOrder.append(0)
		let temp = getMaximumScore(
			inningCount: inningCount,
			isSelected: _isSelected,
			battingOrder: _battingOrder,
			teamInformations: teamInformations
		)
		
		maxScore = max(temp, maxScore)
		_battingOrder.removeLast()
	} else {
		for num in (1..<9) {
			if _isSelected[num] { continue }
			
			_battingOrder.append(num)
			_isSelected[num] = true
			let temp = getMaximumScore(
				inningCount: inningCount,
				isSelected: _isSelected,
				battingOrder: _battingOrder,
				teamInformations: teamInformations
			)
			
			maxScore = max(temp, maxScore)
			_battingOrder.removeLast()
			_isSelected[num] = false
		}
	}
	
	return maxScore
}

func getScore(
	inningCount: Int,
	battingOrder: [Int],
	teamInformations: [[Int]]
) -> Int {
	var score = 0
	var battingIndex = 0
	for inning in (0..<inningCount) {
		var inningScore = 0
		var baseInformation = [false, false, false, false]
		var outCount = 0
		
		while outCount < 3 {
			let hitter = battingOrder[battingIndex]
			let hitInfo = teamInformations[inning][hitter]
			
			if hitInfo == 0 {
				outCount += 1
			} else {
				inningScore += hitABall(hitType: hitInfo, &baseInformation)
			}
			
			battingIndex = (battingIndex + 1) % 9
		}
		
		score += inningScore
	}
	
	return score
}

func hitABall(hitType: Int, _ baseInformation: inout [Bool]) -> Int {
	var score = 0
	baseInformation[0] = true
	
	for base in (0..<baseInformation.count) {
		let currentBase = 3 - base
		let afterBase = currentBase + hitType
		
		if !baseInformation[currentBase] { continue }
		baseInformation[currentBase] = false
		if afterBase > 3 {
			score += 1
		} else {
			baseInformation[afterBase] = true
		}
	}
	
	return score
}


func readInteger() -> Int {
	return Int(readLine()!)!
}

func readIntergers() -> [Int] {
	return readLine()!.split(separator: " ").map { Int($0)! }
}

solution()
