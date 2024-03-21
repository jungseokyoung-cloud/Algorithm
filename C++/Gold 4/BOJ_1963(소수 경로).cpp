//
//  BOJ_1963(소수 경로).cpp
//  BOJ
//
//  Created by jung on 3/21/24.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

const int MAXNUM = 9999;

vector<bool> isPrime(MAXNUM + 1, true);
bool isVis[MAXNUM + 1];

void setPrimeNumber() {
	isPrime[1] = false;
	
	for(int i = 2; i*i <= MAXNUM; i++) {
		if(!isPrime[i]) continue;
		for(int j = i*i; j <= MAXNUM; j+=i) {
			isPrime[j] = false;
		}
	}
}

int solve(int st, int en) {
	memset(isVis, false, sizeof(isVis));
	queue<pair<int, int>> q;
	
	isVis[st] = true;
	q.push({st, 0});
	
	while(!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if(now == en) return cnt;
		
		for(int i = 0; i < 4; i++) {
			for(int j = 0; j < 10; j++) {
				if(i == 0 && j == 0) continue;
				string str = to_string(now);
				str[i] = j + '0';
				int next = stoi(str);
				
				if(!isPrime[next] || isVis[next]) continue;
				isVis[next] = true;
				q.push({next, cnt + 1});
			}
		}
	}
	
	return -1;
}

int main() {
	FAST;
	
	int N; cin >> N;
	
	setPrimeNumber();
	while(N--) {
		int st, en;
		cin >> st >> en;
		
		int result = solve(st, en);
		
		if(result != -1) cout << result << endl;
		else cout << "Impossible" << endl;
	}
}
