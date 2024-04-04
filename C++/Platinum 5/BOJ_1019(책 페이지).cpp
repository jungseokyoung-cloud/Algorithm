//
//  BOJ_1019(책 페이지).cpp
//  BOJ
//
//  Created by jung on 4/4/24.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int cnt[10];

void solve(int n) {
	string str = to_string(n);
	
	int div = 1;
	int temp = n;
	
	for(int i = 0; i < str.size()-1; i++, div*=10) {
		for(int j = 0; j <= 9; j++) {
			int num = temp % 10; // 1
			int adder = temp / 10; // 1
			
			if(j > 0 && j < num)  { adder ++; }
			if(j == num) {
				if(j > 0 || (j == 0 && i > 0)) cnt[j] += (n % div + 1);
			}
			
			cnt[j] += (adder * div);
			if(j == 0 && num == j && i > 0) cnt[j] -= div;
		}
		temp /= 10;
	}
	
	int last = str[0] - '0';
	for(int i = 1; i <= last; i++) {
		if(i < last) cnt[i] += (div);
		else cnt[i] += (n % div + 1);
	}
}


int main() {
	FAST;
	int N; cin >> N;
	solve(N);
	for(int i = 0; i < 10; i++) cout << cnt[i] << " ";
}
