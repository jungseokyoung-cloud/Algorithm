//
//  BOJ.cpp
//  BOJ
//
//  Created by jung on 11/17/23.
//

#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

const int MAX = 500000;
int n, k;
bool isVis[MAX + 1][2];

void input() { 
	cin >> n >> k;
	memset(isVis, false, sizeof(isVis));
}

int move(int x, int i) {
	if(i == 0) return x - 1;
	else if(i == 1) return x + 1;
	else return 2*x;
}

int solve() {
	isVis[n][1] = 1;
	queue<tuple<int, int, int>> pos;
	pos.push({n, k, 1});
	
	while(!pos.empty()) {
		int nowN = get<0>(pos.front());
		int nowK = get<1>(pos.front());
		int cnt = get<2>(pos.front());
		pos.pop();
		
		if(nowK > MAX) return -1;
		if(isVis[nowK][cnt % 2]) return cnt - 1;
	
		for(int i = 0; i < 3; i++) {
			int nextN = move(nowN, i);
			int nextCnt = cnt + 1;
			if(nextN < 0 || nextN > MAX) continue;
			if(isVis[nextN][nextCnt % 2] > 0) continue;
			
			isVis[nextN][nextCnt % 2] = true;
			pos.push({nextN, nowK + cnt, nextCnt});
		}
	}
	
	return -1;
}

int main() {
	FAST;
	
	input();
	cout << solve() << endl;
}
