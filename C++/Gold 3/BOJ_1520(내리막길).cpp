//
//  BOJ_.cpp
//  BOJ
//
//  Created by jung on 2/23/24.
//

#include <iostream>
#include <algorithm>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long

int dis_x[] = {-1, 0, 1, 0};
int dis_y[] = {0, -1, 0, 1};

int N, M;
int arr[501][501];
int dp[501][501];

void input() {
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) cin >> arr[i][j];
	}
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) dp[i][j] = -1;
	}
}

int solve(int x, int y) {
	if(x == N-1 && y == M-1) return 1;
	if(dp[x][y] != -1) return dp[x][y];
	dp[x][y] = 0;
	
	for(int i = 0; i < 4; i++) {
		int nx = x + dis_x[i];
		int ny = y + dis_y[i];

		if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		if(arr[nx][ny] >= arr[x][y]) continue;
		
		dp[x][y] += solve(nx, ny);
	}
	
	return dp[x][y];
}

int main() {
	FAST;
	input();
	cout << solve(0, 0) << endl;
}
