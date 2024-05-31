//
//  BOJ_23326(홍익 투어리스트).cpp
//  BOJ
//
//  Created by jung on 5/31/24.
//

#include <iostream>
#include <map>
#include <cmath>
#include <vector>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int N, Q;
map<int, int> places;
vector<int> answer;


void input() {
	cin >> N >> Q;
	
	for(int i = 0; i < N; i++) {
		int place; cin >> place;
		if(place == 1) places[i] = true;
	}
}

int processOperation(int opNum, int position) {
	int temp;
	
	if(opNum == 1) {
		cin >> temp;
		temp --;
		if(places.find(temp) != places.end()) places.erase(temp);
		else places[temp] = temp;
		
	} else if(opNum == 2) {
		cin >> temp;
		position = (position + temp) % N;
		
	} else {
		
		auto nextPlace = places.lower_bound(position);
		if(nextPlace == places.end()) {

			auto tempPlace = places.lower_bound(-1);
			if(tempPlace == places.end()) answer.push_back(-1);
			else {
				int placeNum = tempPlace->first;
				answer.push_back(N - position + placeNum);
			}
		}
		else {
			int placeNum = nextPlace->first;
			answer.push_back(abs(placeNum - position));
		}
		
	}
	
	return position;
}

void solve() {
	int position = 0;
	int operation;
	while(Q--) {
		cin >> operation;
		position = processOperation(operation, position);
	}
	
	for(auto res: answer) cout << res << endl;
}

int main() {
	FAST;
	input();
	solve();
}
