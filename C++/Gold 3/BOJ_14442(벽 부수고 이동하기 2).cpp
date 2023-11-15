//
//  BOJ_.cpp
//  BOJ
//
//  Created by jung on 11/14/23.
//

#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int n, m, k;
char arr[1000][1000];
int isVis[1000][1000][10];
int maxHeight;

void input() {
	cin >> n >> m >> k;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) cin >> arr[i][j];
	}
}

int solve() {
	queue<tuple<int, int, int>> pos;
	pos.push({0, 0, k});
	isVis[0][0][k] = 1;
	
	while(!pos.empty()) {
		int x = get<0>(pos.front());
		int y = get<1>(pos.front());
		int nk = get<2>(pos.front());
		int cnt = isVis[x][y][nk];
		pos.pop();

		if(x == n-1 && y == m-1) return cnt;
		
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			
			if(isVis[nx][ny][nk] == 0 && arr[nx][ny] == '0') {
				pos.push({nx, ny, nk});
				isVis[nx][ny][nk] = cnt + 1;
			}
			
			if(arr[nx][ny] == '1' && nk > 0 && isVis[nx][ny][nk-1] == 0) {
				pos.push({nx, ny, nk - 1});
				isVis[nx][ny][nk - 1] = cnt + 1;
			}
		}
	}
	
	return -1;
}

int main() {
	FAST;
	input();
	cout << solve() << endl;
}
