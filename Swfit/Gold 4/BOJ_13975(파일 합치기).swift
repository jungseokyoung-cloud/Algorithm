//
//  BOJ_13975(파일 합치기).swift
//  BOJ2
//
//  Created by jung on 4/30/24.
//

import Foundation

final class FileIO {
	private let buffer: Data
	private var index: Int = 0
	
	init(fileHandle: FileHandle = FileHandle.standardInput) {
		self.buffer = try! fileHandle.readToEnd()! // 인덱스 범위 넘어가는 것 방지
	}
	
	@inline(__always) private func read() -> UInt8 {
		defer {
			index += 1
		}
		guard index < buffer.count else { return 0 }
		
		return buffer[index]
	}
	
	@inline(__always) func readInt() -> Int {
		var sum = 0
		var now = read()
		var isPositive = true
		
		while now == 10
						|| now == 32 { now = read() } // 공백과 줄바꿈 무시
		if now == 45 { isPositive.toggle(); now = read() } // 음수 처리
		while now >= 48, now <= 57 {
			sum = sum * 10 + Int(now-48)
			now = read()
		}
		
		return sum * (isPositive ? 1:-1)
	}
	
	
	@inline(__always) func readString() -> String {
		var str = ""
		var now = read()
		
		while now == 10
						|| now == 32 { now = read() } // 공백과 줄바꿈 무시
		
		while now != 10
						&& now != 32 && now != 0 {
			str += String(bytes: [now], encoding: .ascii)!
			now = read()
		}
		
		return str
	}
}

struct Heap<T: Comparable> {
	enum HeapType {
		case min, max
	}
	
	private var nodes: [T] = []
	private let sort: (T, T) -> Bool
	
	var isEmpty: Bool { nodes.isEmpty }
	var count: Int { nodes.count }
	
	init(type: HeapType) {
		switch type {
			case .min:
				sort = { $0 < $1 }
			case .max:
				sort = { $0 > $1 }
		}
	}
	
	mutating func insert(_ element: T) {
		nodes.append(element)
		shiftUp()
	}
	
	@discardableResult
	mutating func remove() -> T? {
		guard !isEmpty else { return nil }
		
		defer {
			nodes.swapAt(0, nodes.count - 1)
			nodes.removeLast()
			shiftDown()
		}
		
		return nodes[0]
	}
	
	func printAll() {
		nodes.forEach { print($0) }
	}
}

private extension Heap {
	mutating func shiftUp() {
		var now = nodes.count - 1
		var parent = getParent(of: now)
		
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
			
			if left < nodes.count && sort(nodes[left], nodes[now]) {
				candidate = left
			}
			if right < nodes.count && sort(nodes[right], nodes[now]) && sort(nodes[right] ,nodes[left]) {
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

struct PriorityQueue<T: Comparable> {
	var heap: Heap<T>
	
	var isEmpty: Bool { heap.isEmpty }
	var count: Int { heap.count }
	
	init(type: Heap<T>.HeapType) {
		heap = Heap(type: type)
	}
	
	mutating func push(_ element: T) {
		heap.insert(element)
	}
	
	@discardableResult
	mutating func pop() -> T? {
		return heap.remove()
	}
	
	func printAll() {
		heap.printAll()
	}
}

func solve(k: Int, nums: [Int]) -> Int {
	
	var answer = 0
	var pq = PriorityQueue<Int>(type: .min)
	
	nums.forEach { pq.push($0) }
	
	while pq.count != 1 {
		let num1 = pq.pop()!
		let num2 = pq.pop()!
		
		let temp = num1 + num2
		answer += temp
		pq.push(temp)
	}
	return answer
}

func solution() {
	var result = ""
	
	let testCase = Int(readLine()!)!
	for _ in (0..<testCase) {
		let k = Int(readLine()!)!
		let nums = readLine()!.split(separator: " ").map {Int($0)!}
		result += "\(solve(k: k, nums: nums))\n"
	}
	
	print(result)
}

solution()
