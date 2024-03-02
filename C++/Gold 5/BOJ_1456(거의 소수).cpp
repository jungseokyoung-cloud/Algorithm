//
//  BOJ_.cpp
//  BOJ
//
//  Created by jung on 3/2/24.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll unsigned long long

vector<bool> isPrime(1e7+1, true);
vector<int> primeNumber;
ll MMAX = UINT64_MAX;

void getPrimeNumber() {
	isPrime[1] = false;
	
	for(int i = 2; i*i <= 1e7; i++) {
		if(!isPrime[i]) continue;
		
		for(int j = i*i; j <= 1e7; j+=i) {
			isPrime[j] = false;
		}
	}
	
	for(int i = 2; i <= 1e7; i++) {
		if(!isPrime[i]) continue;
		primeNumber.push_back(i);
	}
}

int solve(ll st, ll en) {
	queue<pair<ll, int>> q;
	
	int cnt = 0;
	for(int i = 0; i < primeNumber.size(); i++) {
		ll temp = (ll)primeNumber[i] * primeNumber[i];

		if(temp > en) break;
		q.push({temp, i});
	}
	
	while(!q.empty()) {
		ll num = q.front().first;
		int index = q.front().second;
				
		q.pop();
		if(num >= st) cnt ++;
		if(MMAX / primeNumber[index] + MMAX % MMAX < num) continue;
		ll next = num * primeNumber[index];
		if(next <= en) q.push({next, index});
	}
	
	return cnt;
}

int main() {
	FAST;
	ll st, en;
	cin >> st >> en;
	getPrimeNumber();
	
	cout << solve(st, en) << endl;
}
