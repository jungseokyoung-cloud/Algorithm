#include <iostream>
#include <algorithm>
#include <vector>

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

using namespace std;

int N, D, K, C;
int sushis[3000000];
int isEat[3001];

void init() {
	cin >> N >> D >> K >> C;
	for(int i = 0; i < N; i++) cin >> sushis[i];
}

int solve() {
	int maxSushi = 0, temp = 1;
	isEat[C]++;
	
	for(int i = 0; i < K; i++) {
		if(isEat[sushis[i]] == 0) temp ++;
		isEat[sushis[i]] ++;
	}
	maxSushi = temp;

	for(int i = 0; i < N - 1; i++) {
		int popSushi = sushis[i];
		int pushSushi = sushis[(i + K) % N];
		
		if(isEat[pushSushi]++ == 0) temp ++;
		if(--isEat[popSushi] == 0) temp --;
		
		maxSushi = max(temp, maxSushi);
	}
	
	return maxSushi;
}

int main() {
	FAST;
	init();
	cout << solve() << endl;
}
