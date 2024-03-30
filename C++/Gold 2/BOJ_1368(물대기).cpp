//
//  BOJ_1368(물대기).cpp
//  BOJ
//
//  Created by jung on 3/22/24.
//

#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long

int N;
int parants[302], levels[302];

vector<tuple<int, int, int>> edges;

void input() {
	cin >> N;
	
	int cost;
	for(int i = 0; i < N; i++) {
		cin >> cost;
		edges.push_back({cost, i, N});
	}
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> cost;
			if(i == j || i > j) continue;
			edges.push_back({cost, i, j});
		}
	}
}

int find(int node) {
	if(parants[node] == node) return node;
	return parants[node] = find(parants[node]);
}

bool isSameParant(int nodeA, int nodeB) {
	return find(nodeA) == find(nodeB);
}

void unionParant(int nodeA, int nodeB) {
	int rootA = find(nodeA);
	int rootB = find(nodeB);
	
	if(levels[rootA] < levels[rootB]) swap(rootA, rootB);
	
	parants[rootB] = rootA;
	if(levels[rootA] == levels[rootB]) levels[rootA] ++;
}


int solve() {
	int result = 0;
	sort(edges.begin(), edges.end());
	
	for(int i = 0; i <= N; i++) parants[i] = i;
	int cnt = 0;
	for(int i = 0; i < edges.size(); i++) {
		int cost, node1, node2;
		tie(cost, node1, node2) = edges[i];
		if(cnt == N) break;
		
		if(isSameParant(node1, node2)) continue;
		unionParant(node1, node2);
		result += cost;
	}
	
	return result;
}

int main() {
	FAST;
	input();
	cout << solve() << endl;
}



/*
 직접 파기 || 끌어오기
 
 1. 이중 가장 값이 작은 거를 파. (1개를)
 
 2. 연결하느냐 파느냐..!
 ... 일단 파는 비용순으로 정렬.
 
 1. 일단 다파.
 
 2. 그래서 비용이 가장 적은 애를 기준으로 파느냐 있느냐.
 
 */
