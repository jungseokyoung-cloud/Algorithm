//
//  BOJ_19700(수업).cpp
//  BOJ
//
//  Created by jung on 6/4/24.
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int N;
map<int, int> teams;
vector<pair<int, int>> temp;

void input() {
	cin >> N;
	
	for(int i = 0; i < N; i++) {
		int height, k; cin >> height >> k;
		temp.push_back({height, k});
	}
	
	sort(temp.begin(), temp.end());
}

void insertTeam(int key) {
	if(teams.find(key) != teams.end()) {
		teams[key] ++;
	} else {
		teams[key] = 1;
	}
}

void removeTeam(int key) {
	if(teams.find(key) == teams.end()) return;
	teams[key] --;

	if(teams[key] == 0) teams.erase(key);
}

int solve() {
	int result = 0;
	int lastIndex = (int)temp.size() - 1;
	teams[1] = 1;
	
	for(int i = lastIndex-1; i >= 0; i--) {
		auto iter = teams.lower_bound(temp[i].second);
		
		if(iter == teams.begin()) {
			insertTeam(1);
		} else {
			advance(iter, -1);
			removeTeam(iter->first);
			insertTeam(iter->first + 1);
		}
	}
	
	for(auto res: teams) result += res.second;
	
	return result;
}

int main() {
	FAST;
	input();
	
	cout << solve() << endl;
}
