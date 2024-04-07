//
//  BOJ_18870(좌표 압축).cpp
//  BOJ
//
//  Created by jung on 4/7/24.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int N;
int arr[1000000];
vector<int> result;

void input() {
	cin >> N;
	for(int i = 0; i < N; i++) cin >> arr[i];
}

void solve() {
	vector<int> temp;
	
	for(int i = 0; i < N; i++) temp.push_back(arr[i]);
	sort(temp.begin(), temp.end());
	
	// 좌표 압축!
	temp.erase(unique(temp.begin(), temp.end()), temp.end());
	
	for(int i = 0; i < N; i++) {
		int idx = int(lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin());
		result.push_back(idx);
	}
}

int main() {
	FAST;
	input();
	solve();
	for(auto res: result) cout << res << " ";
}
