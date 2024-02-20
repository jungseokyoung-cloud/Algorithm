//
//  BOJ_.cpp
//  BOJ
//
//  Created by jung on 2/19/24.
//

#include <iostream>
#include <algorithm>

using namespace std;

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll long long

int N;
int arr[100000];
ll result = 0;

void input() {
	cin >> N;
	for(int i = 0; i < N; i++) cin >> arr[i];
}

void solve() {
	sort(arr, arr + N);
	
	for(int i = N-1; i >= 0; i--) {
		ll count = N - i;
		
		result = max(arr[i] * count, result);
	}
}

int main() {
	FAST;
	input();
	solve();
	cout << result << endl;
}
