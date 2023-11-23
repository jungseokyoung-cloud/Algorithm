//
//  C++.cpp
//  BOJ
//
//  Created by jung on 11/20/23.
//

#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int n, m, redCount, greenCount, result;
vector<pair<int, int>> seed;
vector<tuple<int, int, int>> spreadSeed;

bool isSpread[11];
int arr[51][51];

void input() {
	cin >> n >> m >> greenCount >> redCount;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if(arr[i][j] == 2) seed.push_back({i, j});
		}
	}
}

int getFlowerCount() {
	int flowerCount = 0;
	queue<tuple<int, int, int>> pos;
	int isVis[51][51][2];
	
	for(int i = 0; i< 51; i++) {
		for(int j = 0; j < 51; j++) fill(isVis[i][j], isVis[i][j]+2, 0);
	}
	
	for(auto res: spreadSeed) {
		pos.push(res);
		isVis[get<0>(res)][get<1>(res)][get<2>(res)] = 1;
	}
	
	while(!pos.empty()) {
		int x = get<0>(pos.front());
		int y = get<1>(pos.front());
		int seed = get<2>(pos.front());
		int cnt = isVis[x][y][seed];
		pos.pop();

		if(cnt == -1) continue;
		
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(isVis[nx][ny][seed] != 0 || arr[nx][ny] == 0) continue;
			
			// 꽃 피는 경우
			if(isVis[nx][ny][(seed+1)%2] > 0 && isVis[nx][ny][(seed+1)%2] == cnt + 1) {
				flowerCount ++;
				isVis[nx][ny][(seed+1)%2] = -1;
				isVis[nx][ny][seed] = -1;
			} 
			// 아직 배양액이 없는 경우
			else if(isVis[nx][ny][(seed+1)%2] == 0) {
				pos.push({nx, ny, seed});
				isVis[nx][ny][seed] = cnt + 1;
			}
		}
		
	}
	return flowerCount;
}



void solve(int idx ,int r, int g) {
	if(r == redCount && g == greenCount) {
		result = max(result, getFlowerCount());
		return;
	}
	
	for(int i = idx; i < seed.size(); i++) {
		if(isSpread[i]) continue;
		isSpread[i] = true;
		if(r < redCount) {
			spreadSeed.push_back({seed[i].first, seed[i].second, 0});
			solve(i+1, r+1, g);
			spreadSeed.pop_back();
		}
		if(g < greenCount) {
			spreadSeed.push_back({seed[i].first, seed[i].second, 1});
			solve(i+1, r, g+1);
			spreadSeed.pop_back();
		}
		isSpread[i] = false;
	}
}

int main() {
	FAST;
	input();
	solve(0, 0, 0);
	cout << result << endl;
}

/*
 예제 5
 예제 8
 */
