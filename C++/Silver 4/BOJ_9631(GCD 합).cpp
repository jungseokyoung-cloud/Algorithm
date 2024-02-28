//
//  BOJ_.cpp
//  BOJ
//
//  Created by jung on 2/28/24.
//

#include <iostream>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long

int N;
int arr[100];

int gcd(int a, int b) {
	if(a == 0) return b;
	return gcd(b%a ,a);
}

void input() {
	cin >> N;
	for(int i = 0; i < N; i++) cin >> arr[i];
}

ll solve() {
	ll total = 0;
	
	for(int i = 0; i < N; i++) {
		for(int j =  i+1; j < N; j++) {
			total += (ll)gcd(arr[i], arr[j]);
		}
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
