//
//  BOJ_20366(같이 눈사람 만들래? ).swift
//  BOJ2
//
//  Created by jung on 7/10/24.
//

func solution() {
	var result = 0x3f3f3f3f
	
	let n = readInterger()
	let heights = readIntegers()
	let sortedHeights = heights.sorted()
	
	let size = sortedHeights.count

	for i in 0..<size {
		if i + 2 > size { continue }
		
		for j in (i+2)..<size {
			let heightA = sortedHeights[i] + sortedHeights[j]
			
			var en = j - 1
			
			for st in (i+1)..<size {
				var heightB = sortedHeights[st] + sortedHeights[en]
				if st < en { result = min(result, abs(heightA - heightB)) }
				
				while st < en && heightB > heightA {
					en -= 1
					heightB = sortedHeights[st] + sortedHeights[en];
					if st < en {
						result = min(abs(heightA - heightB), result)
					}
				}
			}
		}
	}
	print(result)
}

func readInterger() -> Int {
	Int(readLine()!)!
}

func readIntegers() -> [Int] {
	return readLine()!.split(separator: " ").map { Int($0)! }
}

solution()
