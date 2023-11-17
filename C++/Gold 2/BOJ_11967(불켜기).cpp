//
//  BOJ_.cpp
//  BOJ
//
//  Created by jung on 11/17/23.
//

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cstring>
using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int n, m;
vector<pair<int, int>> arr[101][101];
bool isVis[101][101];
bool isTurnOn[101][101];

void input() {
	cin >> n >> m;
	memset(isVis, false, sizeof(isVis));
	memset(isTurnOn, false, sizeof(isTurnOn));
	for(int i = 0; i < m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		arr[a][b].push_back({c,d});
	}
}

int solve() {
	int result = 1;
	queue<pair<int, int>> pos;
	isVis[1][1] = 1;
	isTurnOn[1][1] = true;
	
	pos.push({1, 1});
	
	while(!pos.empty()) {
		int x = pos.front().first;
		int y = pos.front().second;
		pos.pop();
		
		int addCnt = 0;
		for(int i = 0; i < arr[x][y].size(); i++) {
			int tempX = arr[x][y][i].first;
			int tempY = arr[x][y][i].second;
			if(!isTurnOn[tempX][tempY]) addCnt++;
			isTurnOn[tempX][tempY] = true;
			
			if(isVis[tempX][tempY] != 0) continue;
			
			bool canGo = false;
			for(int dis = 0; dis < 4; dis++) {
				int nx = tempX + dx[dis];
				int ny = tempY + dy[dis];
				
				if(nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
				if(isVis[nx][ny] == 0) continue;
				canGo = true;
				break;
			}
			if(!canGo) continue;
			isVis[tempX][tempY] = 1;
			pos.push({tempX, tempY});
		}
		
		result += addCnt;

		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
			if(isVis[nx][ny] > 0 || !isTurnOn[nx][ny]) continue;
			
			isVis[nx][ny] = 1;
			pos.push({nx, ny});
		}
	}
	
	return result;
}

int main() {
	FAST;
	input();
	cout << solve() << endl;
}
