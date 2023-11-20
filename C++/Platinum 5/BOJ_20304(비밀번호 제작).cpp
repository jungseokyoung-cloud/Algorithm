//
//  BOJ_20304(비밀번호 제작).cpp
//  BOJ
//
//  Created by jung on 11/19/23.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int isVis[1000001];
int tempNumber[100000];
int n, m;

void input() {
	fill(isVis, isVis+1000001, -1);
	cin >> n >> m;
	
	for(int i = 0; i < m; i++) cin >> tempNumber[i];
}

int solve() {
	int ans = 0;
	queue<int> pos;

	for(int i = 0; i < m; i++) {
		pos.push(tempNumber[i]);
		isVis[tempNumber[i]] = 0;
	}

	while(!pos.empty()) {
		int now = pos.front();
		int cnt = isVis[now];
		pos.pop();
		
		ans = max(cnt, ans);
		
		int shift = 1;
		
		for(int i = 0; i <= 20; i++) {
			int next = (1<<i) ^ now;
			if(next > n || isVis[next] != -1) continue;
			
			isVis[next] = cnt + 1;
			pos.push(next);
		}
		
	}
	return ans;
}

int main() {
	FAST;
	input();
	cout << solve() << endl;
}
