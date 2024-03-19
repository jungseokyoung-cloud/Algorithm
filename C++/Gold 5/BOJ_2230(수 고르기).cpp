//
//  BOJ_2230(수 고르기).cpp
//  BOJ
//
//  Created by jung on 3/18/24.
//

#include <iostream>
#include <algorithm>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N, M;
int arr[100000];

void input() {
	cin >> N >> M;
	for(int i = 0; i < N; i++) cin >> arr[i];
}

int binarySolution() {
	int result = 2e9;
	sort(arr, arr + N);

	for(int i = 0; i < N; i++) {
		int idx = lower_bound(arr, arr + N, arr[i] + M) - arr;
		
		if(idx == N) continue;
		result = min(result, arr[idx] - arr[i]);
	}
	
	return result;
}

int twoPoint() {
	int result = 2e9;
	int st = 0, en = 0;
	sort(arr, arr + N);
	
	while(en != N) {
		if(arr[en] - arr[st] >= M) {
			result = min(result, arr[en] - arr[st]);
			st ++;
		}
		else en ++;
	}
	
	return result;
}

int solve() {
	return twoPoint();
}

int main() {
	FAST;
	input();
	cout << solve() << endl;
}
