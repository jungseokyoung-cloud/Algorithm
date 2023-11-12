//
//  main.cpp
//  BOJ
//
//  Created by jung on 11/11/23.
//

#include <iostream>
#include <stack>
#include <utility>

using namespace std;

#define FAST ios::sync_with_stdio, cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll long long

int n;
int arr[100000];

void input() {
	for(int i = 0; i < n; i++) cin >> arr[i];
}

ll solve() {
	ll result = 0;
	stack<pair<ll, int>> st;
	
	for(int i = 0; i < n; i++) {
		int minIdx = i;

		while(!st.empty() && st.top().first > arr[i]) {
			auto top = st.top();
			st.pop();

			minIdx = min(minIdx, top.second);
			ll area = top.first * (i - top.second);

			result = max(result, area);
		}
		
		st.push({arr[i], minIdx});
	}
	
	while(!st.empty()) {
		auto top = st.top();
		st.pop();
		
		ll area = top.first * (n - top.second);
		result = max(result, area);
	}
	
	return result;
}

int main() {
	FAST;
	
	while(1) {
		cin >> n;
		if (n == 0) return 0;
		input();
		cout << solve() << endl;
	}
}
