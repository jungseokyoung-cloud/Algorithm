//
//  BOJ.cpp
//  BOJ
//
//  Created by jung on 11/12/23.
//

#include <iostream>
#include <utility>
#include <deque>

using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long

deque<pair<ll, int>> dq;

int main() {
	FAST;
	
	int n, l;
	cin >> n >> l;
		
	for(int i = 0; i < n; i++) {
		ll num; cin >> num;
		
		int lowerIndex = (i - l);
		if(lowerIndex < 0) lowerIndex = 0;
		else {
			if(!dq.empty() && dq.front().second == lowerIndex) dq.pop_front();
		}
		
		while(!dq.empty() && dq.back().first > num) {
			dq.pop_back();
		}
		dq.push_back({num, i});
		cout << dq.front().first << " ";
	}
	cout << endl;
}
