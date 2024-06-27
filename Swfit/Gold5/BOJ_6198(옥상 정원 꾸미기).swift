//
//  BOJ_6198(옥상 정원 꾸미기).swift
//  BOJ2
//
//  Created by jung on 6/27/24.
//

import Foundation

struct Stack<T> {
	private var elements = [T]()
	
	var size: Int { elements.count }
	
	var isEmpty: Bool { elements.isEmpty }
	
	var top: T? { elements.last }
	
	mutating func push(_ element: T) {
		elements.append(element)
	}
	
	@discardableResult
	mutating func pop() -> T? {
		return elements.popLast()
	}
}

func solution() {
	let n = readInterger()
	var buildings = [Int]()
	var stack = Stack<Int>()
	var answer = 0
	
	for _ in (0..<n) {
		buildings.append(readInterger())
	}
	
	for building in buildings {
		// 현재 높이보다 작은 친구들을 날려 <그럼 큰 친구만 남음>
		while let top = stack.top, top <= building {
			stack.pop()
		}
		
		answer += stack.size
		stack.push(building)
	}
	
	print(answer)
}

func readInterger() -> Int {
	return Int(readLine()!)!
}

solution()
