//
//  BOJ_18868(멀티버스 Ⅱ).swift
//  BOJ2
//
//  Created by jung on 7/8/24.
//


func solution() {
	let (n, _) = baseInput()
	var universes = [[Int]]()
	var sortedUniverses = [[Int]]()
	var results = [[Int]]()
	var answer = 0
	
	for _ in 0..<n { universes.append(readIntegers()) }
	
	let removeDuplicated = Array(universes.map { Set($0) })
	removeDuplicated.forEach { sortedUniverses.append($0.sorted()) }
		
	for (idx, universe) in universes.enumerated() {
		results.append([Int]())
		for planet in universe {
			let count = sortedUniverses[idx].lowerBound(to: planet)
			
			results[idx].append(count)
		}
	}
	
	for index1 in (0..<universes.count) {

		for index2 in (index1+1..<universes.count) {
			if results[index1] == results[index2] {
				answer += 1
			}
		}
	}
	
	print(answer)
}

func baseInput() -> (Int, Int) {
	let base = readIntegers()
	return (base[0], base[1])
}

func readIntegers() -> [Int] {
	return readLine()!.split(separator: " ").map { Int($0)! }
}

// MARK: - Array Extension
extension Array where Element: Comparable {
	func lowerBound(to target: Element) -> Int {
		var st = 0
		var en = self.count
		
		while st < en {
			let mid = (st + en) / 2
			
			if target > self[mid] {
				st = mid + 1
			} else {
				en = mid
			}
		}
		
		return en
	}
}

solution()
