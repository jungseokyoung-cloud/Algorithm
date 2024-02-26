//
//  BOJ_17140(이차원 배열과 연산).cpp
//  BOJ
//
//  Created by jung on 2/26/24.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int arr[101][101];
int r, c, k;
int rowCnt = 3;
int colCnt = 3;

void input() {
	cin >> r >> c >> k;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) cin >> arr[i][j];
	}
}

bool comp(pair<int, int> a, pair<int, int> b) {
	if(a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

void getSortedCntAndNumber(vector<int> &temp, vector<pair<int, int>> &result) {
	if(temp.size() == 0) return;
	sort(temp.begin(), temp.end());
	
	result.push_back({temp[0], 1});
	
	for(int i = 1; i < temp.size(); i++) {
		if(result.back().first == temp[i]) result.back().second++;
		else result.push_back({temp[i], 1});
	}
	
	sort(result.begin(), result.end(), comp);
}

void rOperator() {
	rowCnt = 0;
	
	for(int i = 0; i < colCnt; i++) {
		vector<int> temp; // 예를 정렬하고!!! 각각 몇개 있는지 알아봊!
		vector<pair<int, int>> result;
		
		for(int j = 0; j < 100; j++) {
			if(arr[i][j] == 0) continue;
			temp.push_back(arr[i][j]);
		}
		
		getSortedCntAndNumber(temp, result);
		
		int index = 0;
		int resultIndex = 0;
		while(index < 100 && resultIndex < result.size()) {
			arr[i][index++] = result[resultIndex].first;
			arr[i][index++] = result[resultIndex++].second;
		}
		// Row Count 업데이트
		rowCnt = max(rowCnt, index);

		while(index < 100) arr[i][index++] = 0;
	}
}

void cOperator() {
	colCnt = 0;
	
	for(int i = 0; i < rowCnt; i++) {
		vector<int> temp; // 예를 정렬하고!!! 각각 몇개 있는지 알아봊!
		vector<pair<int, int>> result;
		
		for(int j = 0; j < 100; j++) {
			if(arr[j][i] == 0) continue;
			temp.push_back(arr[j][i]);
		}
		
		getSortedCntAndNumber(temp, result);

		int index = 0;
		int resultIndex = 0;
		while(index < 100 && resultIndex < result.size()) {
			arr[index++][i] = result[resultIndex].first;
			arr[index++][i] = result[resultIndex++].second;
		}
		colCnt = max(colCnt, index);
		
		while(index < 100) arr[index++][i] = 0;
	}
}

int solve() {
	if(arr[r-1][c-1] == k) return 0;
	int t = 0;
	
	while(t < 100) {
		if(colCnt >= rowCnt) rOperator();
		else cOperator();
		
		t++;
		if(arr[r-1][c-1] == k) return t;
	}
	
	return -1;
}

int main() {
	FAST;
	input();
	cout << solve() << endl;
}
