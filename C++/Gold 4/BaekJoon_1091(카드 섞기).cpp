#include <iostream>
#include <set>
#include <string>
#include <queue>
#include <vector>

using namespace std;
int N;
string st;
int ordered[50];
set<string> isVis;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

void init() {
	cin >> N;
	for(int i = 0; i < N; i++) {
		char c;
		cin >> c;
		st.push_back(c);
	}
	
	for(int i = 0; i < N; i++) {
		int index;
		cin >> index;
		ordered[index] = i;
	}
}

bool checkAnser(string &s) {
	for(int i = 0; i < s.size(); i++) {
		int now = s[i] - '0';
		int playerNum = i % 3;

		if(now != playerNum) return false;
	}
	return true;
}

int solve() {
	isVis.insert(st);
	queue<pair<string, int>> q;
	q.push({st, 0});
	
	while(!q.empty()) {
		string now = q.front().first;
		int cnt = q.front().second;
		
		q.pop();
		if(checkAnser(now)) return cnt;
		
		string temp = "";
		for(int i = 0; i < N; i++) {
			temp.push_back(now[ordered[i]]);
		}
		if(isVis.find(temp) != isVis.end()) continue;

		isVis.insert(temp);
		q.push({temp, cnt + 1});
	}
	return -1;
}

int main() {
	FAST;
	init();
	cout << solve() << endl;
}
