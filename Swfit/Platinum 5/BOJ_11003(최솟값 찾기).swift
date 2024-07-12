//
//  BOJ_11003(최솟값 찾기).swift
//  BOJ2
//
//  Created by jung on 7/12/24.
//

import Foundation

class FileIO {
	@inline(__always) private var buffer: [UInt8] = Array(FileHandle.standardInput.readDataToEndOfFile()) + [0], byteIdx = 0
	
	@inline(__always) private func readByte() -> UInt8 {
		defer { byteIdx += 1 }
		return buffer.withUnsafeBufferPointer { $0[byteIdx] }
	}
	
	@inline(__always) func readInt() -> Int {
		var number = 0, byte = readByte(), isNegative = false
		while byte == 10 || byte == 32 { byte = readByte() }
		if byte == 45 { byte = readByte(); isNegative = true }
		while 48...57 ~= byte { number = number * 10 + Int(byte - 48); byte = readByte() }
		return number * (isNegative ? -1 : 1)
	}
	
	@inline(__always) func readStirngSum() -> Int {
		var byte = readByte()
		while byte == 10 || byte == 32 { byte = readByte() }
		var sum = Int(byte)
		while byte != 10 && byte != 32 && byte != 0 { byte = readByte(); sum += Int(byte) }
		return sum - Int(byte)
	}
	
	@inline(__always) private func write(_ output: String) {
		FileHandle.standardOutput.write(output.data(using: .utf8)!)
	}
}

class DeQueue<T> {
	var elements = [T]()
	var frontCursor = 0
	
	var size: Int { elements.count - frontCursor }
	var top: T? {
		guard size != 0 else { return nil }
		return elements.last
	}
	var front: T? {
		guard size != 0 else { return nil }
		return elements[frontCursor]
	}
	
	func append(_ element: T) {
		elements.append(element)
	}
	
	@discardableResult
	func pop_front() -> T? {
		guard size != 0 else { return nil }
		defer { frontCursor += 1 }
		
		return elements[frontCursor]
	}
	
	@discardableResult
	func pop_back() -> T? {
		guard size != 0 else { return nil }
		
		return elements.removeLast()
	}
}

func solution() {
	let fileIO = FileIO()
	var numbers = [Int]()
	
	let n = fileIO.readInt()
	let l = fileIO.readInt()
	
	for _ in 0..<n { numbers.append(fileIO.readInt()) }
	let dq = DeQueue<(Int, Int)>()
	var results = [Int]()
	
	for index in 0..<n {
		let minIndex = index - l < 0 ? 0 : index - l
		
		// 삭제
		if index - l >= 0,
			 let front = dq.front,
			 front.1 == minIndex {
			dq.pop_front()
		}
		
		// 추가
		while let top = dq.top, top.0 > numbers[index] { dq.pop_back() }
		dq.append((numbers[index], index))
		results.append(dq.front!.0)
	}
	print(results.map { "\($0)" }.joined(separator: " "))
}

solution()
