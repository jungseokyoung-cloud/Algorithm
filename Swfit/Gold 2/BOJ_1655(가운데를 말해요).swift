//
//  BOJ_1655.swift
//  BOJ2
//
//  Created by jung on 6/19/24.
//

import Foundation

struct Heap<T: Comparable> {
	enum HeapType {
		case min, max
	}
	
	private var nodes = [T]()
	private let sort: (T, T) -> Bool
	
	var isEmpty: Bool { nodes.isEmpty }
	var count: Int { nodes.count }
	var top: T? {
		guard !isEmpty else { return nil }
		return nodes[0]
	}
	
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
			if right < nodes.count && sort(nodes[right], nodes[now]) && sort(nodes[right], nodes[left]) {
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
	private var heap: Heap<T>
	
	var isEmpty: Bool { heap.isEmpty }
	var count: Int { heap.count }
	var top: T? { heap.top }
	
	init(type: Heap<T>.HeapType) {
		self.heap = Heap(type: type)
	}
	
	mutating func push(_ element: T) {
		heap.insert(element)
	}
	
	@discardableResult
	mutating func pop() -> T? {
		heap.pop()
	}
}

func solution() {
	let n = readInteger()
	var printValue = ""
	
	var maxPq = PriorityQueue<Int>(type: .max)
	var minPq = PriorityQueue<Int>(type: .min)
	
	for _ in (0..<n) {
		let num = readInteger()
		
		maxPq.count > minPq.count ? minPq.push(num) : maxPq.push(num)
		
		if let maxTop = maxPq.top, let minTop = minPq.top, maxTop > minTop {
			maxPq.pop()
			minPq.pop()
			maxPq.push(minTop)
			minPq.push(maxTop)
		}
		
		printValue += "\(maxPq.top!)\n"
	}
	print(String(printValue.dropLast(1)))
}

func readInteger() -> Int {
	return Int(readLine()!)!
}

solution()
