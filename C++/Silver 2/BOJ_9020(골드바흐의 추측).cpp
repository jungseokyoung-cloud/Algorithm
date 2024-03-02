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
#define endl '\n'

vector<bool> isPrime(10001, true);

void getPrime() {
	isPrime[1] = false;
	
	for(int i = 2; i*i <= 10000; i++) {
		if(!isPrime[i]) continue;
		
		for(int j = i*i; j<=10000; j+=i) {
			isPrime[j] = false;
		}
	}
}

int main() {
	FAST;
	int T, N;
	cin >> T;
	getPrime();
	
	while(T--) {
		cin >> N;
		int num1 = 0, num2 = 0;
		
		for(int num = 2; num <= N/2; num++) {
			if(!isPrime[num] || !isPrime[N-num]) continue;
			num1 = num;
			num2 = N - num;
		}
		cout << num1 << " " << num2 << endl;
	}
}
