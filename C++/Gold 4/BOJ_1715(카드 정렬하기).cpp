//
//  BOJ_1715(카드 정렬하기).cpp
//  BOJ
//
//  Created by jung on 3/22/24.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int N;
priority_queue<int, vector<int>, greater<int>> cards;

int solve() {
	if(N == 1) return 0;
	
	int result = 0;
	
	while(cards.size() >= 2) {
		int top1 = cards.top();
		cards.pop();
		int top2 = cards.top();
		cards.pop();
		
		cards.push(top1 + top2);
		result += (top1 + top2);
	}
	
	cards.pop();
	
	return result;
}

int main() {
	FAST;
	cin >> N;

	for(int i = 0; i < N; i++) {
		int num; cin >> num;
		cards.push(num);
	}
	cout << solve() << endl;
}
