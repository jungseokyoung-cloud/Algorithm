//
//  BOJ_7662(이중 우선순위 큐).cpp
//  BOJ
//
//  Created by jung on 3/20/24.
//

#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

string op;
int num;

multiset<int> ms;

void solve(int numOfOperstions) {
	string op;
	int num;
	while(numOfOperstions --) {
		cin >> op >> num;
		if(op == "I") ms.insert(num);
			
		else if(op == "D") {
			if(ms.empty()) continue;
			else if(num == 1) ms.erase(prev(ms.end()));
			else ms.erase(ms.begin());
		}
	}
}

int main() {
	FAST;
	int T; cin >> T;
	
	while(T--) {
		ms.clear();
		int numOfOperations; cin >> numOfOperations;
		
		solve(numOfOperations);
		
		if(ms.empty()) cout << "EMPTY" << endl;
		else {
			cout << *prev(ms.end()) << " " << *ms.begin() << endl;
		}
	}
}
