//
//  main.cpp
//  BOJ
//
//  Created by jung on 11/9/23.
//

#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll long long

ll n;
ll arr[500000];
stack<pair<ll, ll>> st;

int main() {
	FAST;
	
	cin >> n;
	
	for(int i = 0; i < n; i++) cin >> arr[i];
	ll sum = 0;
	
	for(int i = 0; i < n; i++) {
		ll count = 0;
		ll sameCount = 0;
		
		while(!st.empty() && arr[i] >= st.top().first) {
			if(arr[i] == st.top().first) {
				sameCount += (st.top().second + 1);
			}
			
			count += (1 + st.top().second);
			st.pop();
		}
		
		if(!st.empty())  count ++;

		st.push({arr[i], sameCount});
		sum += count;
	}

	cout << sum << endl;
}
