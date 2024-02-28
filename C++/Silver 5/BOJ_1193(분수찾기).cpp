//
//  BOJ.cpp
//  BOJ
//
//  Created by jung on 2/27/24.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int mother, son;

void solve(int n) {
	if(n == 1) {
		mother = 1;
		son = 1;
		return;
	}
	int total = 1;
	int now = 1;
	
	while(1) {
		total += (++now);
		
		if(total >= n) {
			int cnt = total - n;
			mother = cnt + 1;
			son = now - cnt;
			
			if(now % 2 != 0) swap(mother, son);
			return;
		}
	}
	
}

int main() {
	FAST;
	int N;
	cin >> N;
	
	solve(N);
	cout << son << "/" << mother << endl;
	
}
