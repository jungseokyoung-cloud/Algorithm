//
//  BOJ_.cpp
//  BOJ
//
//  Created by jung on 3/2/24.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int N, K;
int arr[101];
bool isValid[101] = {false, };

void input() {
	cin >> N >> K;
	for(int i = 0; i < K; i++) cin >> arr[i];
}

int solve() {
	if(N >= K) return 0;
	
	int cnt = 0;
	vector<int> temp;
	
	for(int i = 0; i < K; i++) {
		if(isValid[arr[i]]) continue;
		
		if(temp.size() < N) {
			temp.push_back(arr[i]);
			isValid[arr[i]] = true;
			continue;
		}
		
		int eraseIndex = 0;
		int recentUse = 0;
		
		// 가장 빨리 사용되는게 가장 늦은 인덱스 구하기.
		for(int j = 0; j < temp.size(); j++) {
			int node = temp[j];
			int currentUse = 101;
			
			for(int k = i; k < K; k++) {
				if(arr[k] != node) continue;
				currentUse = k;
				break;
			}
			
			if(currentUse <= recentUse) continue;
			recentUse = currentUse;
			eraseIndex = j;
		}

		cnt++;
		isValid[temp[eraseIndex]] = false;
		isValid[arr[i]] = true;
		
		temp.erase(temp.begin() + eraseIndex);
		temp.push_back(arr[i]);
	}
	
	return cnt;
}

int main() {
	FAST;
	input();
	cout << solve() << endl;
}
