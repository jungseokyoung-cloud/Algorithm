//
//  BOJ_1351(무한 수열).cpp
//  BOJ
//
//  Created by jung on 4/22/24.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long

ll N, P, Q;
map<ll, ll> vis;

void input() {
	cin >> N >> P >> Q;
}

ll solve(ll n, ll p, ll q) {
	if(vis.find(n) != vis.end()) return vis[n];
		
	ll temp = solve(n/p, p, q) + solve(n/q, p, q);
	vis[n] = temp;
	
	return vis[n];
}

int main() {
	FAST;
	input();
	vis[0] = 1;
	cout << solve(N, P, Q) << endl;
}
