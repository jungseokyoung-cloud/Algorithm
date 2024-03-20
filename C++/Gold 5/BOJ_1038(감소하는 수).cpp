//
//  BOJ_1038(감소하는 수).cpp
//  BOJ
//
//  Created by jung on 3/20/24.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long

vector<int> ans;

ll solve(int n) {
	queue<ll> num;
	
	for(int i = 0; i < 10; i++) num.push(i);
	
	while(!num.empty()) {
		ll now = num.front();
		num.pop();
		if(n-- == 0) return now;
		
		int last = now % 10;
		
		for(int i = 0; i < last; i++) {
			num.push(now * 10 + i);
		}
	}
	
	return -1;
}

int main() {
	FAST;
	int N;
	cin >> N;
	
	cout << solve(N) << endl;
}
