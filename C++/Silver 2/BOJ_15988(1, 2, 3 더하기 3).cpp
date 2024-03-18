//
//  BOJ_15988.cpp
//  BOJ
//
//  Created by jung on 3/18/24.
//

#include <iostream>

using namespace std;

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

const int MOD = 1e9 + 9;

int dp[1000001];

void solve() {
	int MAXNUM = 1000000;
	
	dp[0] = 1;
	dp[1] = 1; // 1
	dp[2] = 2; // 1 + 1, 2
	
	for(int i = 3; i <= MAXNUM; i++) {
		int temp = (dp[i-2] + dp[i-1]) % MOD;
		dp[i] = (temp + dp[i-3]) % MOD;
	}
}

int main() {
	FAST;
	int T; cin >> T;
	
	int N;
	solve();
	while(T--) {
		cin >> N;
		cout << dp[N] << endl;
	}
}
