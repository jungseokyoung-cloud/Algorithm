//
//  main.cpp
//  BOJ
//
//  Created by jung on 2/3/24.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int N, maxScore;
int hitInformaitons[51][9];
int baseInformation[4];
vector<int> battingOrder;
bool isSelected[10];

void input() {
	cin >> N;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < 9; j++) cin >> hitInformaitons[i][j];
	}
	
	for(int i = 0; i < 9; i++) isSelected[i] = false;
}

int getScore(int hitInfo) {
	int score = 0;
	
	baseInformation[0] = 1;
	for(int i = 3; i >= 0; i--) {
		if(baseInformation[i] == 0) continue;
		baseInformation[i] --;

		int temp = i + hitInfo;
		if(temp > 3) score ++;
		else baseInformation[temp] ++;
	}
	
	return score;
}

// 게임 관련된 네이밍으로 변경
void playGame() {
	int score = 0;
	int index = 0;
	
	for(int i = 0; i < N; i++) {
		int outCount = 0;
		for(int j = 0; j < 4; j++) baseInformation[j] = 0;
		
		while(outCount < 3) {
			int hitter = battingOrder[index];
			int hitInfo = hitInformaitons[i][hitter];

			if(hitInfo == 0) outCount ++;
			else score += getScore(hitInfo);
			index = (index + 1) % 9;
		}
	}
	maxScore = max(score, maxScore);
}

void solve(int now) {
	if(now == 9) {
		playGame();
		return;
	}
	
	if(now == 3) {
		battingOrder.push_back(0);
		solve(now + 1);
		battingOrder.pop_back();
	} else {
		for(int i = 1; i < 9; i++) {
			if(isSelected[i]) continue;
			isSelected[i] = true;
			battingOrder.push_back(i);
			solve(now + 1);
			battingOrder.pop_back();
			isSelected[i] = false;
		}
	}
}

int main() {
	FAST;
	input();
	solve(0);
	cout << maxScore << endl;
}
