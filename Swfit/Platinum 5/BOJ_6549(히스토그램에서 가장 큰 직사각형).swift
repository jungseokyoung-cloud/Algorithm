//
//  BOJ_6549(히스토그램에서 가장 큰 직사각형).swift
//  BOJ2
//
//  Created by jung on 7/11/24.
//

func solution() {
	var results = [Int]()
	
	while true {
		let inputs = readIntergers()
		
		if inputs.count == 1 && inputs[0] == 0 { break }
		let squares = Array(inputs[1..<inputs.count])
		results.append(getResult(squares))
	}
	
	results.forEach { print($0) }
}

func getResult(_ squares: [Int]) -> Int {
	var result = 0
	var stack = [(Int, Int)]()
	
	for i in 0..<squares.count {
		var minIndex = i

		while let top = stack.last, top.0 > squares[i] {
			let top = stack.popLast()!
			
			minIndex = top.1
			let area = top.0 * (i - top.1)
			
			result = max(area, result)
		}
		stack.append((squares[i], minIndex))
	}
	while let top = stack.popLast() {
		let area = top.0 * (squares.count - top.1)
		
		result = max(area, result)
	}
	
	return result
}

func readIntergers() -> [Int] {
	readLine()!.split(separator: " ").map { Int($0)! }
}

solution()
