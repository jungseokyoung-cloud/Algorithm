//
//  BOJ_18869(멀티버스).cpp
//  BOJ
//
//  Created by jung on 3/13/24.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long

int M, N;

vector<vector<int>> arr(100);
vector<vector<int>> sortedArr(100);


void input() {
	cin >> M >> N;
	int num;
	for(int i = 0; i < M; i++) {
		for(int j = 0; j < N; j++) {
			cin >> num;
			arr[i].push_back(num);
			sortedArr[i].push_back(num);
		}
	}
}

int solve() {
	int result = 0;
	vector<vector<int>> ans(100);

	for(int i = 0; i < M; i++) {
		sort(sortedArr[i].begin(), sortedArr[i].end());
		sortedArr[i].erase(unique(sortedArr[i].begin(), sortedArr[i].end()), sortedArr[i].end());
	}
	
	for(int i = 0; i < M; i++) {
		for(int j = 0; j < N; j++) {
			auto cnt = lower_bound(sortedArr[i].begin(), sortedArr[i].end(), arr[i][j]) - sortedArr[i].begin();
			
			ans[i].push_back((int)cnt);
		}
	}
	
	for(int i = 0; i < M; i++) {
		for(int j = i+1; j < M; j++) {
			if(ans[i] == ans[j]) result ++;
		}
	}
	
	return result;
}

int main() {
	FAST;

	input();
	cout << solve() << endl;
}
