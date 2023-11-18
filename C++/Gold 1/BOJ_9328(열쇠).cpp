//
//  BOJ_.cpp
//  BOJ
//
//  Created by jung on 11/17/23.
//

#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

char key[26];
char arr[100][100];
bool isVis[100][100];
int n, m;

queue<pair<int, int>> pos;
vector<pair<int, int>> needKey[26];

void input() {
	cin >> n >> m;
	
	memset(key, false, sizeof(key));
	memset(isVis, false, sizeof(isVis));
	for(int i = 0; i < 26; i++) needKey[i].clear();
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	
	string value;
	cin >> value;
	
	for(auto v: value) {
		if(v == '0') break;
		key[v-'a'] = true;
	}
}

void calculate(int x, int y) {
	if(arr[x][y] >= 'A' && arr[x][y] <= 'Z') {
		if(key[arr[x][y] - 'A']) {
			pos.push({x, y});
			isVis[x][y] = true;
			
		} else {
			needKey[arr[x][y] - 'A'].push_back({x, y});
			isVis[x][y] = true;
		}
	} else if(arr[x][y] >= 'a' && arr[x][y] <= 'z') {
		key[arr[x][y] - 'a'] = true;
		pos.push({x, y});
		isVis[x][y] = true;
		
		for(auto s: needKey[arr[x][y] - 'a']) {
			pos.push(s);
		}
	} else {
		pos.push({x, y});
		isVis[x][y] = true;
	}
}

int solve() {
	int count = 0;
	
	for(int i = 0; i < n; i++) {
		if(arr[i][0] != '*' && !isVis[i][0]) calculate(i, 0);
		if(arr[i][m-1] != '*' && !isVis[i][m-1]) calculate(i, m-1);
	}
	
	
	
	for(int i = 0; i < m; i++) {
		if(arr[0][i] != '*' && !isVis[0][i]) calculate(0, i);
		if(arr[n-1][i] != '*' && !isVis[n-1][i]) calculate(n-1, i);
	}
	
	while(!pos.empty()) {
		auto now = pos.front();
		if(arr[now.first][now.second] == '$') count ++;
		pos.pop();
		
		for(int i = 0; i < 4; i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(isVis[nx][ny] || arr[nx][ny] == '*') continue;
			calculate(nx, ny);
		}
	}
	return count;
}

int main() {
	FAST;
	int t; cin >> t;
	while(t--) {
		input();
		cout << solve() << endl;
	}
}
