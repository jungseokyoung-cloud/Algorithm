//
//  BOJ_11779(최소 비용 구하기 2).cpp
//  BOJ
//
//  Created by jung on 3/22/24.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

// 최대 십만 * 1000 -> int 범위 ㄱㅊㄱㅊ
const int INF = 0x3fffffff;

int N, M, st, en;
vector<pair<int, int>> graph[1001];
//int isVis[1001] = {INF, };
vector<int> isVis(1001, INF);
int from[1001];

void input() {
	cin >> N >> M;
	int from, to, cost;
	for(int i = 0; i < M; i++) {
		cin >> from >> to >> cost;
		
		graph[from].push_back({to, cost});
	}
	cin >> st >> en;
	
//	for(int i = 0; i < 1001; i++) if(isVis[i])
}

int solve() {
	priority_queue<pair<int, int>> pos;
	
	pos.push({0, st});
	isVis[st] = 0;
	
	while(!pos.empty()) {
		int now = pos.top().second;
		int cnt = -pos.top().first;
		pos.pop();

		if(isVis[now] < cnt) continue;
		
		for(int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int cost = graph[now][i].second;

			if(cnt + cost >= isVis[next]) continue;
			
			isVis[next] = cnt + cost;
			from[next] = now;
			pos.push({-isVis[next], next});
		}
	}
	
	return isVis[en];
}

void trace() {
	vector<int> path;
	from[st] = -1;

	int now = en;
	
	do {
		path.push_back(now);
		now = from[now];
	} while(now != -1);
	
	cout << path.size() << endl;
	for(int i = (int)path.size() - 1; i >= 0; i--) cout << path[i] << " ";
	cout << endl;
}

int main() {
	FAST;
	input();
	cout << solve() << endl;
	trace();
}
