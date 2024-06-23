//
//  BOJ_2457(공주님의 정원).swift
//  BOJ2
//
//  Created by jung on 6/23/24.
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

struct FlowerDate: Comparable {
	let month: Int
	let day: Int
	
	static func < (lhs: FlowerDate, rhs: FlowerDate) -> Bool {
		if lhs.month == rhs.month {
			return lhs.day < rhs.day
		} else {
			return lhs.month < rhs.month
		}
	}
}

struct Flower: Comparable {
	let stDate: FlowerDate
	let enDate: FlowerDate
	
	init(_ stMonth: Int, _ stDay: Int, _ enMonth: Int, _ enDay: Int) {
		self.stDate = FlowerDate(month: stMonth, day: stDay)
		self.enDate = FlowerDate(month: enMonth, day: enDay)
	}
	
	init(_ arr: [Int]) {
		self.init(arr[0], arr[1], arr[2], arr[3])
	}
	
	static func < (lhs: Flower, rhs: Flower) -> Bool {
		lhs.enDate < rhs.enDate
	}
}

func solution() {
	let n = readInteger()
	var result = 0
	var flowers = [Flower]()
	var currentEnDate = FlowerDate(month: 3, day: 1)
	let targetEnDate = FlowerDate(month: 12, day: 1)
	var priorityQueue = PriorityQueue<Flower>(type: .max)
	
	for _ in (0..<n) {
		let informations = readIntergers()
		flowers.append(.init(informations))
	}
	
	// 시작날짜 기준으로 정렬
	let sortedFlowers = flowers.sorted {
		$0.stDate < $1.stDate
	}

	var flowerIndex = 0
	
	while currentEnDate < targetEnDate {
		// 현재의 꽃이 지는날보다, 먼저 피는 꽃들을 우선순위 큐에 삽입한다.
		while
			flowerIndex < sortedFlowers.count &&
			sortedFlowers[flowerIndex].stDate <= currentEnDate {
			
			priorityQueue.push(sortedFlowers[flowerIndex])
			flowerIndex += 1
		}

		// 이후, 가장 늦게 지는 꽃을 선택한다.
		if let date = priorityQueue.pop() {
			currentEnDate = date.enDate
			result += 1
		} else {
			break
		}
	}
	
	currentEnDate >= targetEnDate ? print(result) : print(0)
}

func readInteger() -> Int {
	Int(readLine()!)!
}

func readIntergers() -> [Int] {
	return readLine()!.split(separator: " ").map { Int($0)! }
}

solution()
