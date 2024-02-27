//
//  BOJ_.cpp
//  BOJ
//
//  Created by jung on 2/26/24.
//

#include <iostream>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

const int MOD = 1000000003;
int N, K;
int dp[1001][1001];

void input() {
	cin >> N >> K;
}

void solve() {
	for(int i = 0; i <= N; i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}
	
	for(int i = 2; i < N; i++) {
		for(int j = 2; j <= K; j++) {
			dp[i][j] = (dp[i-2][j-1] + dp[i-1][j]) % MOD;
		}
	}
}

void printAns() {
	dp[N][K] = (dp[N-3][K-1] + dp[N-1][K]) % MOD;
	cout << dp[N][K] << endl;
}

int main() {
	FAST;
	input();
	solve();
	printAns();
}
