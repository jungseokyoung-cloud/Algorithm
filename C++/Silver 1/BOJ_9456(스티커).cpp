//
//  BOJ_9456(스티커).cpp
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

int N;
int arr[2][100000];
int dp[3][100000];

void input() {
	cin >> N;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < N; j++) cin >> arr[i][j];
	}
}

int max(const int& a, const int& b, const int& c) {
	int temp = a > b ? a : b;
	return temp > c ? temp : c;
}

int solve() {
	dp[0][0] = arr[0][0];
	dp[1][0] = arr[1][0];
	
	for(int i = 1; i < N; i++) {
		// i열의 0번 스티커 선택하는 경우의 수
		dp[0][i] = max(dp[1][i-1], dp[2][i-1]) + arr[0][i];

		// i열의 1번 스티커 선택하는 경우의 수
		dp[1][i] = max(dp[0][i-1], dp[2][i-1]) + arr[1][i];

		// 아무것도 선택하지 않는 경우
		dp[2][i] = max(dp[0][i-1], dp[1][i-1], dp[2][i-1]);
	}
	return max(dp[0][N-1], dp[1][N-1], dp[2][N-1]);
}

int main() {
	FAST;
	int T; cin >> T;
	while(T--) {
		input();
		cout << solve() << endl;
	}
}
