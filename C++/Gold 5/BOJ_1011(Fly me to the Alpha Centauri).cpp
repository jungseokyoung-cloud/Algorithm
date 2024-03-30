//
//  BOJ_1011(Fly me to the Alpha Centauri).cpp
//  BOJ
//
//  Created by jung on 3/29/24.
//

#include <iostream>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long

ll solve(ll st, ll en) {
	ll diff = en - st;
	ll temp = 1;
	ll result = 0;
	
	while(temp * temp <= diff) { temp ++; }
	--temp;
	
	result += (2 * temp - 1);
	
	diff -= (temp * temp);
	result += (diff / temp);
	if(diff % temp != 0) result ++;
	
	return result;
}

int main() {
	FAST;
	int T; cin >> T;
	ll st, en;
	
	while(T--) {
		cin >> st >> en;
		cout << solve(st, en) << endl;
	}
}
