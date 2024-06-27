//
//  BOJ_17298(오큰수).swift
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
	let numbers = readIntergers()
	var stack = Stack<Int>()
	
	var results = Array(repeating: -1, count: n)
	
	for (index, number) in numbers.enumerated() {
		while let top = stack.top, numbers[top] < number {
			results[top] = number
			stack.pop()
		}
		stack.push(index)
	}
	
	let printValue = results.map { "\($0)" }.joined(separator: " ")
	print(printValue)
}

func readInterger() -> Int {
	return Int(readLine()!)!
}

func readIntergers() -> [Int] {
	return readLine()!.split(separator: " ").map { Int($0)! }
}

solution()
