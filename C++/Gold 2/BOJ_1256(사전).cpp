//
//  BOJ_1256(사전).cpp
//  BOJ
//
//  Created by jung on 4/6/24.
//

#include <iostream>
#include <string>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ull unsigned long long

int idx = 1;
string result;
int maxResultSize = 0;
bool impossible = false;
ull combi[201][101];

ull getCombination(int n, int k) {
	if(n < k) return 0;
	
	if(k == 0 || n == k) return 1;
	else if(k == 1) return n;

	if(combi[n][k] != 0) return combi[n][k];
	
	combi[n][k] += getCombination(n-1, k);
	combi[n][k] += getCombination(n-1, k-1);
	
	return combi[n][k];
}

void solve(int aCnt, int zCnt, int k) {
	if(result.size() == maxResultSize || impossible) return;

	ull total = getCombination(aCnt + zCnt, aCnt);
	if(total < k) { impossible = true; return; }
	
	// a가 맨 앞인 경우!
	ull aFront = getCombination(aCnt + zCnt - 1, zCnt);
	
	if(k <= aFront) {
		result.push_back('a');
		return solve(aCnt-1, zCnt, k);
	} else {
		result.push_back('z');
		return solve(aCnt, zCnt-1, k-aFront);
	}
}

int main() {
	FAST;
	int N, M, K;
	cin >> N >> M >> K;
	
	maxResultSize = N + M;
	solve(N, M, K);
	
	if(result.size() != maxResultSize) cout << "-1" << endl;
	else cout << result << endl;
}
