//
//  BOJ_11003(최솟값 찾기).swift
//  BOJ2
//
//  Created by jung on 1/1/25.
//

// MARK: - ADT
protocol StackADT {
  associatedtype T
  
  var count: Int { get }
  var isEmpty: Bool { get }
  var top: T? { get }
  
  mutating func push(_ element: T)
  mutating func pop() -> T?
}

// MARK: - Data Structure
struct Stack<T>: StackADT {
  private var elements: [T] = []
  
  var count: Int { elements.count }
  var isEmpty: Bool { elements.isEmpty }
  var top: T? { elements.last}
}

// MARK: Methods
extension Stack {
  mutating func push(_ element: T) {
    elements.append(element)
  }
  
  @discardableResult
  mutating func pop() -> T? {
    return elements.popLast()
  }
}

// MARK: - Problem
func solution() {
  let personCount = Int(readLine()!)!
  
  var heights = [Int]()
  
  for _ in 0..<personCount {
    let height = Int(readLine()!)!
    heights.append(height)
  }

  let result = solve(for: heights)
  print(result)
}

func solve(for inputs: [Int]) -> Int {
  var result = 0
  var stack = Stack<(Int, Int)>() // 숫자, 동일 갯수
  
  for number in inputs {
    var popCount = 0
    var sameCount = 0
    
    while let top = stack.top, top.0 <= number {
      stack.pop()
      
      if top.0 == number {
        sameCount = top.1
      } else {
        popCount += top.1
      }
    }
    
    result += (popCount + sameCount)
    if !stack.isEmpty { result += 1 }

    stack.push((number, sameCount + 1))
  }
  
  return result
}

solution()
