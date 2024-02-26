//
//  BOJ_.cpp
//  BOJ
//
//  Created by jung on 2/25/24.
//

#include <iostream>
#include <queue>

using namespace std;

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll long long

int N, M;
priority_queue<ll> pq;

void input() {
	cin >> N >> M;
	int num;
	
	for(int i = 0; i < N; i++) {
		cin >> num;
		pq.push(-num);
	}
}

ll topAndPop() {
	ll top = -pq.top();
	pq.pop();
	return top;
}

void solve() {
	while(M--) {
		ll top = topAndPop();
		ll top2 = topAndPop();
			
		ll temp = top + top2;
		pq.push(-temp);
		pq.push(-temp);
	}
}

ll printResult() {
	ll total = 0;
	
	while(!pq.empty()) {
		ll top = -pq.top();
		total += top;
		pq.pop();
	}
	
	return total;
}

int main() {
	FAST;
	input();
	solve();
	cout << printResult() << endl;
}
