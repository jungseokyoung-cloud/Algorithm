//
//  BOJ_21939(문제 추천 시스템 Version 1).swift
//  BOJ2
//
//  Created by jung on 5/28/24.
//

import Foundation

struct Problem: Comparable {
	let id: Int
	let level: Int
	
	static func < (lhs: Problem, rhs: Problem) -> Bool {
		if lhs.level == rhs.level { return lhs.id < rhs.id }
		return lhs.level < rhs.level
	}
}

public enum HeapType {
	case max
	case min
}

public struct Heap<T: Comparable> {
	private var nodes = [T]()
	private let sort: (T, T) -> Bool
	
	public var isEmpty: Bool {
		nodes.isEmpty
	}
	
	public var count: Int {
		nodes.count
	}
	
	public var peek: T? {
		nodes.first
	}
	
	public init(type: HeapType) {
		switch type {
			case .min:
				self.sort = { $0 < $1 }
			case .max:
				self.sort = { $0 > $1 }
		}
	}
}

// MARK: - Public Methods
public extension Heap {
	mutating func insert(_ element: T) {
		nodes.append(element)
		shiftUp()
	}
	
	mutating func pop() -> T? {
		guard !isEmpty else { return nil }
		
		defer {
			nodes.swapAt(0, nodes.count - 1)
			nodes.removeLast()
			shiftDown()
		}
		
		return nodes[0]
	}
}

struct PrioriyQueue<T: Comparable> {
	private var heap: Heap<T>
	
	var isEmpty: Bool { heap.isEmpty }
	var top: T? { heap.peek }
	
	init(type: HeapType) {
		self.heap = Heap(type: type)
	}
	
	mutating func push(_ element: T) {
		self.heap.insert(element)
	}
	
	@discardableResult
	mutating func pop() -> T? {
		self.heap.pop()
	}
}

// MARK: - Private Methods
private extension Heap {
	mutating func shiftUp() {
		var now = nodes.count - 1
		var parent = getParent(of: now)
		
		// now가 0인 경우는 트리의 루트에 도착한 경우, 부모 값과 비교해서 바꿔야 하는 경우
		while now > 0 && sort(nodes[now], nodes[parent]) {
			nodes.swapAt(now, parent)
			now = parent
			parent = getParent(of: now)
		}
	}
	
	mutating func shiftDown() {
		var now = 0
		while true {
			let (left, right) = getChilds(of: now)
			var candidate = now
			
			if left < nodes.count && sort(nodes[left], nodes[candidate]) {
				candidate = left
			}
			
			if right < nodes.count && sort(nodes[right], nodes[candidate]) && sort(nodes[right], nodes[left]) {
				candidate = right
			}
			
			if candidate == now { return }
			
			nodes.swapAt(now, candidate)
			now = candidate
		}
		
	}
	
	func getParent(of node: Int) -> Int {
		return (node - 1) / 2
	}
	
	func getChilds(of node: Int) -> (left: Int, right: Int) {
		return (node * 2 + 1, node * 2 + 2)
	}
}

enum OperationType {
	case add(Problem)
	case recommend(Int)
	case solved(Int)
}

func solution() {
	var problemForMax = [Int: Int]()
	var problemForMin = [Int: Int]()

	var maxQueue = PrioriyQueue<Problem>(type: .max)
	var minQueue = PrioriyQueue<Problem>(type: .min)

	var printValue = ""
	
	// MARK: - Input
	let n = readInteger()
	
	for _ in (0..<n) {
		let problem = readProblem()
		
		maxQueue.push(problem)
		minQueue.push(problem)
		problemForMax[problem.id] = problem.level
		problemForMin[problem.id] = problem.level
	}

	
	// MARK: - Solve
	let l = readInteger()
	
	for _ in (0..<l) {
		let operation = readOperation()
		
		switch operation {
			case let .add(problem):
				maxQueue.push(problem)
				minQueue.push(problem)
				problemForMax[problem.id] = problem.level
				problemForMin[problem.id] = problem.level


			case let .solved(id):
				problemForMax[id] = nil
				problemForMin[id] = nil
				
			case let .recommend(value):
				if value == 1 {
					while let top = maxQueue.top {
//						print(top.id)
						if problemForMax[top.id] == nil || problemForMax[top.id] != top.level {
							maxQueue.pop()
						} else {
							printValue.append("\(top.id)\n")
							break
						}
					}
				} else {
					while let top = minQueue.top {
//						print("\(top.id)")
						if problemForMin[top.id] == nil || problemForMin[top.id] != top.level {
							minQueue.pop()
						} else {
//							print("\(top.id)")
							printValue.append("\(top.id)\n")
							break
						}
					}
				}
		}
	}
	
	print(printValue)
}


func readProblem() -> Problem {
	let input = readIntegers()
	
	return .init(id: input[0], level: input[1])
}

func readInteger() -> Int {
	return Int(readLine()!)!
}

func readIntegers() -> [Int] {
	return readLine()!.split(separator: " ").map { Int($0)! }
}

func readOperation() -> OperationType {
	let operations = readLine()!.split(separator: " ")
	
	switch operations[0] {
		case "add":
			return .add(.init(id: Int(operations[1])!, level: Int(operations[2])!))
		case "solved":
			return.solved(Int(operations[1])!)
		default:
			return .recommend(Int(operations[1])!)
	}
}

solution()
