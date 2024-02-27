//
//  BOJ_.cpp
//  BOJ
//
//  Created by jung on 2/27/24.
//

#include <iostream>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long

int N;
ll arr[1000000];

void input() {
	cin >> N;
	for(int i = 0; i < N; i++) cin >> arr[i];
}

ll solve() {
	ll total = 0;
	
	int index = N-2;
	ll now = arr[N-1];
	
	while(index >= 0) {
		if(now < arr[index]) now = arr[index];
		else total += (now - arr[index]);
		index--;
	}
	
	return total;
}

int main() {
	FAST;
	int T;
	cin >> T;
	
	while(T--) {
		input();
		cout << solve() << endl;
	}
}
