//
//  BOJ_.cpp
//  BOJ
//
//  Created by jung on 3/6/24.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long

int M, N;
int arr[1000000];

void input() {
	cin >> M >> N;
	for(int i = 0; i < N; i++) cin >> arr[i];
}

ll getCnt(int size) {
	ll total = 0;
	
	for(int i = 0; i < N; i++) total += (arr[i] / size);
	
	return total;
}

int solve() {
	sort(arr, arr + N);
	
	int st = 1, en = arr[N-1]+1;
	
	// upper Bound
	while(st < en) {
		int mid = (st + en) / 2;
		
		if(getCnt(mid) < M) en = mid;
		else st = mid + 1;
	}
	
	return en - 1;
}

int main() {
	FAST;
	input();
	cout << solve() << endl;
}
