//
//  BOJ_2457().cpp
//  BOJ
//
//  Created by jung on 3/19/24.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N;
vector<int> primeNumber;
vector<bool> isPrime(4e6, true);

void input() {
	cin >> N;
}

void setPrimenumber() {
	isPrime[1] = false;
	
	for(int i = 2; i*i <= N; i++) {
		if(!isPrime[i]) continue;
		
		for(int j = i*i; j <= N; j+=i) {
			isPrime[j] = false;
		}
	}
	
	for(int i = 2; i <= N; i++) {
		if(isPrime[i]) primeNumber.push_back(i);
	}
}

int solve() {
	setPrimenumber();
	if(primeNumber.size() == 0) return 0;
	
	int cnt = 0;
	
	int st = 0, en = 1;
	int total = primeNumber[0];
	
	while(en <= primeNumber.size()) {
		if(total == N) cnt ++;
		
		if(total >= N) total -= primeNumber[st++];
		else total += primeNumber[en++];
	}
	
	return cnt;
}

int main() {
	FAST;
	input();
	cout << solve() << endl;
}
