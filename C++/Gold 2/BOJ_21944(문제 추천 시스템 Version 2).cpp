//
//  BOJ_21944(문제 추천 시스템 Version 2).cpp
//  BOJ
//
//  Created by jung on 6/1/24.
//

#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long

struct Problem {
	int id, level, group;
};

struct CustomCompare {
	bool operator()(const Problem& a, const Problem& b) const {
		if(a.level == b.level) return a.id < b.id;
		return a.level < b.level;
	}
};

unordered_map<int, Problem> problemContainer;
map<Problem, bool, CustomCompare> totalProblem;
map<Problem, bool, CustomCompare> groupedProblem[101];

int N, M;
vector<int> answer;

void insert(int p, int l, int g);

void input() {
	cin >> N;
	
	int p, l, g;
	for(int i = 0; i < N; i++) {
		cin >> p >> l >> g;
		insert(p, l, g);
	}
	cin >> M;
}

void insert(int p, int l, int g) {
	Problem temp = {p, l, g};
	problemContainer[p] = temp;
	totalProblem[temp] = true;
	groupedProblem[g][temp] = true;
}

void remove(int p) {
	auto iter = problemContainer.find(p);
	Problem problem = iter->second;
	
	totalProblem.erase(problem);
	groupedProblem[problem.group].erase(problem);
}

int findByGroup(int group, int temp) {
	if(temp == 1) {
		auto iter = groupedProblem[group].end();
		advance(iter, -1);
		return iter->first.id;
	} else {
		return groupedProblem[group].begin()->first.id;
	}
}

int findProblem(int temp) {
	if(temp == 1) {
		auto iter = totalProblem.end();
		advance(iter, -1);
		return iter->first.id;
	} else {
		return totalProblem.begin()->first.id;
	}
}

int findLowerBound(int level, int temp) {
	Problem tempProblem = {0, level, 0};
	auto iter = totalProblem.lower_bound(tempProblem);
	
	if(temp == 1 && iter != totalProblem.end()) {
		return iter->first.id;
	} else if(temp == -1 && iter != totalProblem.begin()) {
		
		advance(iter, -1);
		return iter->first.id;
	} else {
		return -1;
	}
}

void solve() {
	string op;
	
	while(M--) {
		cin >> op;
		
		if(op == "add") {
			int p, l, g; cin >> p >> l >> g;
			insert(p, l, g);
		} else if(op == "solved") {
			int p; cin >> p;
			remove(p);
		} else if(op == "recommend") {
			int g, x; cin >> g >> x;
			answer.push_back(findByGroup(g, x));
		} else if(op == "recommend2") {
			int x; cin >> x;
			answer.push_back(findProblem(x));

		} else if(op == "recommend3") {
			int x, l; cin >> x >> l;
			answer.push_back(findLowerBound(l, x));
		}
	}
}

int main() {
	FAST;
	input();
	solve();
	for(auto res: answer) cout << res << endl;
}
