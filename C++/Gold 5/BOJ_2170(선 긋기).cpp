//
//  BOJ_.cpp
//  BOJ
//
//  Created by jung on 2/25/24.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int N;
pair<int, int> arr[1000000];

void input() {
	cin >> N;
	for(int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
}

int solve() {
	int len = 0;
	
	sort(arr, arr + N);
	int st = arr[0].first;
	int en = arr[0].second;
	
	for(int i = 1; i < N; i++) {
		// 길이만 연장
		if(arr[i].first <= en) en = max(en, arr[i].second);
		else {
			len += (en - st);
			st = arr[i].first;
			en = arr[i].second;
		}
	}
	
	len += (en - st);
	
	return len;
}

int main() {
	FAST;
	input();
	cout << solve() << endl;
}
