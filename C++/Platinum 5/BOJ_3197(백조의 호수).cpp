//
//  BOJ_3197(백조의 호수).cpp
//  BOJ
//
//  Created by jung on 11/18/23.
//

#include <iostream>
#include <utility>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cstring>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int r, c;
char arr[1500][1500];
bool isVis[1500][1500][2];
int meltMap[1500][1500];
int maxMelDay = 0;
pair<int, int> st[2];
queue<tuple<int ,int, int>> pos;


void input() {
	memset(isVis, false, sizeof(isVis));

	cin >> r >> c;
	
	int idx = 0;
	
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			cin >> arr[i][j];
			
			if(arr[i][j] == 'L') st[idx++] = {i, j};
		}
	}
}

void drawMeltMap() {
	queue<pair<int, int>> posForDot;
	queue<pair<int, int>> melt;

	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			if(arr[i][j] == '.') {
				meltMap[i][j] = -1;
				posForDot.push({i, j});
			}
		}
	}
	
	while(!posForDot.empty()) {
		auto now = posForDot.front();
		posForDot.pop();
		
		for(int i = 0; i < 4; i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			
			if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if(meltMap[nx][ny] != 0) continue;
			if(arr[nx][ny] == 'X') {
				melt.push({nx, ny});
				meltMap[nx][ny] = 1;
			} else {
				posForDot.push({nx, ny});
				meltMap[nx][ny] = -1;
			}
		}
	}
	
	while(!melt.empty()) {
		auto now = melt.front();
		int cnt = meltMap[now.first][now.second];
		melt.pop();
		
		maxMelDay = max(maxMelDay, cnt);
		
		for(int i = 0; i < 4; i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			
			if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if(meltMap[nx][ny] > 0 || arr[nx][ny] != 'X') continue;
			melt.push({nx, ny});
			meltMap[nx][ny] = cnt + 1;
		}
	}
}

int bfs(int day) {
	queue<tuple<int, int, int>> nextPos;
	
	while(!pos.empty()) {
		int x = get<0>(pos.front());
		int y = get<1>(pos.front());
		int idx = get<2>(pos.front());
		pos.pop();

		if(isVis[x][y][(idx + 1) % 2] > 0) return day;
		
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if(isVis[nx][ny][idx]) continue;
			if(arr[nx][ny] == 'X' && meltMap[nx][ny] > day) {
				nextPos.push({nx, ny, idx});
				isVis[nx][ny][idx] = true;
			} else {
				pos.push({nx, ny, idx});
				isVis[nx][ny][idx] = true;
			}
		}
		
	}
	
	pos = nextPos;
	return -1;
}

int solve() {
	drawMeltMap();

	pos.push({st[0].first, st[0].second, 0});
	pos.push({st[1].first, st[1].second, 1});

	isVis[st[0].first][st[0].second][0] = true;
	isVis[st[1].first][st[1].second][1] = true;

	
	for(int i = 0; i <= maxMelDay; i++) {
		int result = bfs(i);
		if(result != -1) return result;
	}
	return 0;
}


int main() {
	FAST;
	input();
	cout << solve() << endl;
}
