//
//  BOJ_5214(환승).swift
//  BOJ2
//
//  Created by jung on 5/5/24.
//

import Foundation

struct Queue<T> {
	private var elements = [T]()
	private var index = 0
	
	var isEmpty: Bool {
		elements.count == index
	}
	
	var count: Int {
		elements.count - index
	}
	
	init() { }
	
	mutating func push(_ element: T) {
		elements.append(element)
	}

	@discardableResult
	mutating func pop() -> T? {
		guard !isEmpty else { return nil }
		defer {
			index += 1
			if index >= 100000 { reAllocation() }
		}
		
		return elements[index]
	}
	
	mutating func reAllocation() {
		self.elements = Array(elements[index..<elements.count])
	}
}

func solution() {
	// MARK: - Input
	let (n, k, m) = baseInput()
	var graph = Array(repeating: [Int](), count: n + m)

	for hiperCnt in (0..<m) {
		let hiperTube = readIntegers()
		let hiperNode = n + hiperCnt
		
		for idx in (0..<k) {
			let node = hiperTube[idx] - 1
			
			graph[node].append(hiperNode)
			graph[hiperNode].append(node)
		}
	}
	
	print(bfs(from: 0, to: n - 1, graph))
}

func bfs(
	from source: Int,
	to destination: Int,
	_ graph: [[Int]]
) -> Int {
	let n = graph.count
	var isVis: [Int] = Array(repeating: 0, count: n)
	var queue = Queue<Int>()
	
	queue.push(source)
	isVis[source] = 1
	
	while !queue.isEmpty {
		let now = queue.pop()!
		let cnt = isVis[now]
		
		if now == destination { return isVis[now] - (isVis[now] / 2) }
		
		for next in graph[now] {
			if isVis[next] == 0 {
				isVis[next] = cnt + 1
				queue.push(next)
			}
		}
	}
	
	return -1
}

func baseInput() -> (n: Int, k: Int, m: Int) {
	let input = readIntegers()
	
	return (input[0], input[1], input[2])
}

func readIntegers() -> [Int] {
	return readLine()!.split(separator: " ").map { Int($0)! }
}

solution()
