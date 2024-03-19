//
//  BOJ_1806(부분합).cpp
//  BOJ
//
//  Created by jung on 3/18/24.
//

#include <iostream>
#include <algorithm>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int N, S;
int arr[100000];

void input() {
	cin >> N >> S;
	for(int i = 0; i < N; i++) cin >> arr[i];
}

int solve() {
	int result = 1e6;
	// 반열린 구간 [st, en)
	int st = 0, en = 1;
	
	int temp = arr[0];
	
	while(en <= N) {
		if(temp >= S) {
			result = min(result, en - st);
			temp -= arr[st++];
		} else {
			temp += arr[en++];
		}
	}
	
	return result == 1e6 ? 0 : result;
}

int main() {
	FAST;
	input();
	cout << solve() << endl;
}
