//
//  BOJ_.cpp
//  BOJ
//
//  Created by jung on 2/12/24.
//

#include <iostream>
#include <algorithm>

using namespace std;

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int T, W;
int arr[1001];
int dp[1001][31][2];
int result = 0;

void input() {
	cin >> T >> W;
	for(int i = 0; i < T; i++) cin >> arr[i];
	
	for(int i = 0; i < 1001; i++) {
		for(int j = 0; j < 31; j++) {
			dp[i][j][0] = -1;
			dp[i][j][1] = -1;
		}
	}
}

int solve(int t, int w, int position) {
	if(t == T) return 0;
	if(dp[t][w][position] != -1) return dp[t][w][position];
	
	int& current = dp[t][w][position];
	int moveTemp = w == W ? -100000 : solve(t+1, w+1, (position+1) % 2);
	int holdTemp = solve(t+1, w, position);

	if(arr[t] == position + 1) {
		current = max(moveTemp, holdTemp + 1);
	} else {
		current = max(moveTemp + 1, holdTemp);
	}

	return current;
}

int main() {
	FAST;
	input();
	cout << solve(0, 0, 0) << endl;
}
