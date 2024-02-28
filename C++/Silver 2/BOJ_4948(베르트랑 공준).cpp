//
//  BOJ_.cpp
//  BOJ
//
//  Created by jung on 2/28/24.
//

#include <iostream>
#include <vector>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int N;
const int MAX = 123456 * 2;
vector<bool> isPrime(MAX, true);
vector<int> primeNumber;

void checkPrimeNumber() {
	isPrime[1] = false;
	
	for(int i = 2; i*i <= MAX; i++) {
		if(!isPrime[i]) continue;

		for(int j = i*2; j <= MAX; j+=i) {
			isPrime[j] = false;
		}
	}
	
	for(int i = 2; i <= MAX; i++) {
		if(isPrime[i]) 	primeNumber.push_back(i);
	}
}

int solve(int n) {
	int cnt = 0;
	
	for(int i = 0; i < primeNumber.size(); i++) {
		if(primeNumber[i] > n && primeNumber[i] <= 2*n) cnt ++;
	}
	
	return cnt;
}


int main() {
	FAST;
	checkPrimeNumber();
	int N;
	while(1) {
		cin >> N;
		if(N == 0) return 0;
		
		cout << solve(N) << endl;
	}
	
}

