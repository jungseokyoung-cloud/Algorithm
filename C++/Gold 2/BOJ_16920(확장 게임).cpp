//
//  BOJ.cpp
//  BOJ
//
//  Created by jung on 11/15/23.
//

#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, m, p;
char arr[1000][1000];
int isVis[1000][1000];
int nextVis[1000][1000];

int s[10];
int result[10];
bool finishMoved[10];
queue<pair<int, int>> pos[10];

void input() {
	cin >> n >> m >> p;
	
	memset(finishMoved, false, sizeof(finishMoved));
	
	for(int i = 0; i < p; i++) cin >> s[i];
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) cin >> arr[i][j];
	}
}

void pushToQueue() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(arr[i][j] == '.' || arr[i][j] == '#') continue;
			int index = arr[i][j] - '0' - 1;

			pos[index].push({i, j});
			isVis[i][j] = 1;
		}
	}
}

bool bfs(int idx) {
	bool isChanged = false;
	
	queue<pair<int, int>> npos;
	
	while(!pos[idx].empty()) {
		auto now = pos[idx].front();
		int cnt = isVis[now.first][now.second];
		pos[idx].pop();
//		cout << now.first << " " << now.second << endl;
//		cout << cnt << endl;
		if(cnt - 1 == s[idx]) {
			npos.push(now);
			continue;
		}
		
		for(int i = 0; i < 4; i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(isVis[nx][ny] > 0 || arr[nx][ny] != '.') continue;
			
			isChanged = true;
			isVis[nx][ny] = cnt + 1;
			arr[nx][ny] = idx + 1 + '0';
			pos[idx].push({nx, ny});
		}
	}
	
	if(isChanged == false) finishMoved[idx] = true;
	else {
		while(!npos.empty()) {
			pos[idx].push(npos.front());
			isVis[npos.front().first][npos.front().second] = 1;
			npos.pop();
		}
	}
	return isChanged;
}

// O(NM)
bool move() {
	bool isChanged = false;
	for(int i = 0; i < p; i++) {
		if (finishMoved[i]) continue;;
		if(bfs(i)) isChanged = true;
	}
	
	return isChanged;
}

void solve() {
	pushToQueue();
	while(1) {
		bool isChanged = move();
		if(!isChanged) return;
	
	}
}

void print() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(arr[i][j] == '.' || arr[i][j] == '#') continue;
			int index = arr[i][j] - '0' - 1;
			
			result[index] ++;
		}
	}
	
	for(int i = 0; i < p; i++) cout << result[i] << " ";
	cout << endl;
}

int main() {
	FAST;
	input();
	solve();
	print();
}
