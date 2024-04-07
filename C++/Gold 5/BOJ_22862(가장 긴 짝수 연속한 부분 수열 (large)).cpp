//
//  BOJ_22862(가장 긴 짝수 연속한 부분 수열 (large)).cpp
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

int N, K;
int arr[1000000];

void input() {
	cin >> N >> K;
	for(int i = 0; i < N; i++) cin >> arr[i];
}

int solve() {
	vector<int> temp;
	int len = 0;
	

	for(int i = 0; i < N; i++) {
		int removeCnt = 0;

		while(arr[i] % 2 != 0) { i ++; removeCnt ++; }

		if(temp.size() == 0) removeCnt = 0;
		if(i < N) temp.push_back(removeCnt);
	}

	int en = 1;
	int cnt = 0;

	for(int st = 0; st < temp.size(); st++) {
		cnt -= temp[st];

		while(en < temp.size()) {
			int comp = cnt + temp[en];
			if(comp > K) break;
			
			cnt = comp;
			en ++;
		}
		len = max(len, en - st);
	}
	
	return len;
}

int main() {
	FAST;
	input();
	cout << solve() << endl;
}
