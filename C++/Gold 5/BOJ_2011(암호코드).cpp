//
//  BOJ_.cpp
//  BOJ
//
//  Created by jung on 2/20/24.
//

#include <iostream>
#include <string>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

const int MOD = 1000000;
string password;
int dp[5001];

void input() {
	cin >> password;
}

bool canPassword(int from, int to) {
	int temp = 0;
	
	for(int i = from-1; i < to; i++) {
		temp = temp*10 + password[i] - '0';
	}

	return temp >= 10 && temp <= 26;
}

int solve() {
	if(password[0] == '0') return 0;
	
	int size = (int)password.size();
	dp[0] = 1;
	dp[1] = 1;
	
	for(int i = 2; i <= size; i++) {
		if(password[i-1] != '0') dp[i] += dp[i-1] ;
		if(canPassword(i-1, i)) dp[i] += dp[i-2];
		dp[i] %= MOD;
		if(dp[i] == 0) return 0;
	}
	
	return dp[size];
}

int main() {
	FAST;
	input();
	cout << solve() << endl;
}
