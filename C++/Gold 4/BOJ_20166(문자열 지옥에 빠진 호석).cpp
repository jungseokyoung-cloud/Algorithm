//
//  BOJ_20166(문자열 지옥에 빠진 호석).cpp
//  BOJ
//
//  Created by jung on 4/23/24.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int N, M, K;
int maxSize = 0;
char arr[11][11];

map<string, int> target;
vector<string> ans;

void input() {
	cin >> N >> M >> K;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) cin >> arr[i][j];
	}
	
	for(int i = 0; i < K; i++) {
		string s; cin >> s;
		ans.push_back(s);
		target[s] = 0;
	}
}

pair<int, int> getNextPos(int x, int y) {
	if(x < 0) x = N-1;
	else x = x % N;
	if(y < 0) y = M-1;
	else y = y % M;
	
	return {x, y};
}

void bfs(int stX, int stY) {
	queue<tuple<int, int, string>> pos;
	
	string str; str.push_back(arr[stX][stY]);
	
	pos.push({stX, stY, str});
	
	while(!pos.empty()) {
		int x, y;
		string now;
		tie(x, y, now) = pos.front();
		pos.pop();
		
		if(target.find(now) != target.end()) target[now] ++;
		if(now.size() == 5) continue;
		for(int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			string temp = now;
			
			tie(nx, ny) = getNextPos(nx, ny);
			temp.push_back(arr[nx][ny]);
			pos.push({nx, ny, temp});
		}
	}
}

void solve() { 
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			bfs(i, j);
		}
	}
}

int main() {
	FAST;
	input();
	solve();
	
	for(int i = 0; i < ans.size(); i++) {
		string str = ans[i];
		cout << target[str] << endl;
	}
}
