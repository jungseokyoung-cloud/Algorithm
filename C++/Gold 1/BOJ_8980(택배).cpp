//
//  BOJ_.cpp
//  BOJ
//
//  Created by jung on 3/5/24.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

struct ProductInfo {
	int from, to, cnt;
};

int N, C, M;
int cap[2001];
vector<ProductInfo> info;

// 가장 빨리(to가 가장 작은거)
// to가 같다면 from
bool comp(ProductInfo a, ProductInfo b) {
	if(a.to == b.to) return a.from < b.from;
	return a.to < b.to;
}

void input() {
	cin >> N >> C >> M;
	
	for(int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		
		info.push_back({a, b, c});
	}
}

int solve() {
	sort(info.begin(), info.end(), comp);
	
	int result = 0;
	
	for(int i = 0; i < M; i++) {
		int from = info[i].from;
		int to = info[i].to;
		int cnt = info[i].cnt;
		
		int minCnt = cnt;
		
		for(int j = from; j < to; j++) minCnt = min(minCnt, C-cap[j]);
		for(int j = from; j < to; j++) cap[j] += minCnt;
		
		result += minCnt;
	}
	return result;
}

int main() {
	FAST;
	input(); 
	cout << solve() << endl;
}
