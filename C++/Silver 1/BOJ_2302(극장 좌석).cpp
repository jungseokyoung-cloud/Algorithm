//
//  BOJ_2302(극장 좌석).cpp
//  BOJ
//
//  Created by jung on 3/18/24.
//

#include <iostream>
#include <vector>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int N, M;
bool isVIP[41] = {false, };
// VIP신경쓰지 않고 배치 가능한 경우의 수!
int dp[41];

void input() {
	cin >> N >> M;
	
	int num;
	for(int i = 0; i < M; i++) {
		cin >> num;
		isVIP[num] = true;
	}
}

void setTable() {
	dp[0] = 1; dp[1] = 1;
	
	for(int i = 2; i < 41; i++) {
		// 변경하지 않는 경우 + 변경하는 경우
		dp[i] = dp[i-1] + dp[i-2];
 	}
}

int solve() {
	setTable();
	
	int result = 1;
	int temp = 0;
	
	for(int i = 1; i <= N; i++) {
		if(isVIP[i]) {
			result *= dp[temp];
			temp = 0;
			continue;
		}
		temp ++;
	}
	result *= dp[temp];
	
	return result;
}

int main() {
	FAST;
	input();
	cout << solve() << endl;;
}
