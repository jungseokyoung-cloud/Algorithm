//
//  BOJ_2461(대표 선수).cpp
//  BOJ
//
//  Created by jung on 4/12/24.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int N, M;
int arr[1000][1000];
vector<pair<int, int>> temp;
int isSelected[1000];


void input() {
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			int num; cin >> num;
			temp.push_back({num, i});
		}
	}
}

int solve() {
	sort(temp.begin(), temp.end());
	
	int result = 0x3fffffff;
	isSelected[temp[0].second] = 1;
	int selectedCount = 1;
	
	int en = 1;
	for(int st = 0; st < temp.size(); st++) {
		while(en < temp.size() && selectedCount < N) {
			auto now = temp[en++];
			isSelected[now.second] ++;
			if(isSelected[now.second] == 1) selectedCount++;
		}

		if(selectedCount == N) result = min(result, temp[en-1].first - temp[st].first);
		isSelected[temp[st].second] --;
		if(isSelected[temp[st].second] == 0) selectedCount --;
	}
	
	return result;
}

int main() {
	FAST;
	input();
	cout << solve() << endl;
}
