//
//  BOJ_2293(동전 1).cpp
//  BOJ
//
//  Created by jung on 3/18/24.
//

#include <iostream>
#include <algorithm>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long

int N, K;
int arr[101];
int temp[10001];
int dp[10001];

void input() {
	cin >> N >> K;
	
	for(int i = 1; i <= N; i++) cin >> arr[i];
}

int before_solve() {
	for(int i = 1; i <= N; i++) {
		int coin = arr[i];

		for(int j = 0; j < min(coin, K); j++) dp[j] = temp[j];

 		for(int j = coin; j <= K; j++) {
			// i번째 코인없이 만드는 법 + i번째 코인쓰고 만드는법!
			dp[j] = temp[j] + dp[j-coin];
		}

		for(int j = 0; j <= K; j++) temp[j] = dp[j];
	}

	return dp[K];
}

int solve() {
	dp[0] = 1;

	for(int i = 1; i <= N; i++) {
		int coin = arr[i];
		
		for(int j = coin; j <= K; j++) {
			dp[j] += dp[j-coin];
		}
	}

	return dp[K];
}

int main() {
	FAST;
	input();
	cout << solve() << endl;
}
