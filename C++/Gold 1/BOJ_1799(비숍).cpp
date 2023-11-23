//
//  BOJ_.cpp
//  BOJ
//
//  Created by jung on 11/23/23.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int n, result;
int resultBlack, resultWhite;
int arr[10][10];
bool leftDir[10];
bool rightDir[10];
vector<pair<int, int>> blackPos;
vector<pair<int, int>> whitePos;

void input() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> arr[i][j];
			
			if(arr[i][j] != 1) continue;
			if(i % 2 == 0 && j % 2 == 0) blackPos.push_back({i, j});
			else if(i % 2 == 1 && j % 2 == 1) blackPos.push_back({i, j});
			else whitePos.push_back({i, j});
		}
	}
}

void solveWhite(int idx, int bishopCount) {
	resultWhite = max(bishopCount, resultWhite);
	
	for(int i = idx; i < whitePos.size(); i++) {
		int x = whitePos[i].first;
		int y = whitePos[i].second;
		if(leftDir[y-x + (n-1)] || rightDir[x+y]) continue;
		leftDir[y-x + (n-1)] = true;
		rightDir[x+y] = true;
		solveWhite(i+1, bishopCount + 1);
		leftDir[y-x + (n-1)] = false;
		rightDir[x+y] = false;
	}
}

void solveBlack(int idx, int bishopCount) {
	resultBlack = max(bishopCount, resultBlack);

	for(int i = idx; i < blackPos.size(); i++) {
		int x = blackPos[i].first;
		int y = blackPos[i].second;
		if(leftDir[y-x + (n-1)] || rightDir[x+y]) continue;
		leftDir[y-x + (n-1)] = true;
		rightDir[x+y] = true;
		solveBlack(i+1, bishopCount + 1);
		leftDir[y-x + (n-1)] = false;
		rightDir[x+y] = false;
	}
}

void solve() {
	memset(rightDir, false, sizeof(rightDir));
	memset(leftDir, false, sizeof(leftDir));

	solveBlack(0, 0);
	solveWhite(0, 0);

	result = resultWhite + resultBlack;
}

int main() {
	FAST;
	input();
	solve();
	
	cout << result << endl;
}
