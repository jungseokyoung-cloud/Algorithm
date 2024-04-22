//
//  BOJ_2283(구간 자르기).cpp
//  BOJ
//
//  Created by jung on 4/22/24.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int N, K;
vector<pair<int, int>> pos;
int totalCnt[1000001];
int minValue = 0;
int maxValue = 1000000;

int ans_st, ans_en;

void input() {
	cin >> N >> K;
	
	for(int i = 0; i < N; i++) {
		int st, en;
		cin >> st >> en;
		pos.push_back({st , en});
		maxValue = max(maxValue, en);
		minValue = min(minValue, st);
		for(int j = st; j < en; j++) totalCnt[j] += 1;
	}
}

void solve() {
	int sum = totalCnt[minValue];
	int en = minValue + 1;
	
	for(int st = minValue; st <= maxValue; st++) {
		while(en <= maxValue && sum < K) {
			sum += totalCnt[en++];
		}

		if(sum == K) {
			ans_st = st;
			ans_en = en;
			return;
		}
		sum -= totalCnt[st];
	}
}

int main() {
	FAST;
	input();
	solve();
	cout << ans_st << " " << ans_en << endl;
}
