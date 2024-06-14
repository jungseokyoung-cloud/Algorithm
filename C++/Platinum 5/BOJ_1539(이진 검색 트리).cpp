//
//  BOJ_19700(수업).cpp
//  BOJ
//
//  Created by jung on 6/14/24.
//

#include <iostream>
#include <map>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long

struct NodeInfo {
	bool hasLeft, hasRight;
	int height;
};

int N;
map<int, NodeInfo> node;

ll solve() {
	ll total = 0;
	cin >> N;
	
	int num;
	for(int i = 0; i < N; i++) {
		cin >> num;
		if(node.size() == 0) {
			node[num] = {false, false, 1};
			continue;
		}
		
		auto iter = node.lower_bound(num);
		
		if(iter == node.end()) {
			advance(iter, -1);
			
			iter->second.hasRight = true;
			node[num] = {false, false, iter->second.height + 1};
		} else {
			// 왼쪽이 있는 경우
			if(iter->second.hasLeft) {
				advance(iter, -1);
				
				iter->second.hasRight = true;
				node[num] = {false, false, iter->second.height + 1};
			// 왼쪽이 없는 경우
			} else {
				iter->second.hasLeft = true;
				node[num] = {false, false, iter->second.height + 1};
			}
		}
	}
	
	for(auto res: node) {
		total += res.second.height;
	}
	
	return total;
}

int main(){
	FAST;
	cout << solve() << endl;
}
