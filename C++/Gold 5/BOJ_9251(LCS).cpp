//
//  BOJ_4883(삼각 그래프).cpp
//  BOJ
//
//  Created by jung on 3/18/24.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

string s1, s2;
int dp[1001][1001];

void input() {
	cin >> s1 >> s2;
	
	s1 = '0' + s1;
	s2 = '0' + s2;
}

int solve() {
	// i번째 문자까지 사용했을 때, 최장 증가는?
	for(int i = 1; i < s1.size(); i++) {
		for(int j = 1; j < s2.size(); j++) {
			if(i == 0 || j == 0) continue;
			
			if(s1[i] == s2[j]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	return dp[s1.size()-1][s2.size()-1];
}

int main() {
	FAST;
	
	input();
	cout << solve() << endl;
}
