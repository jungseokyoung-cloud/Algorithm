//
//  BOJ_1202(보석 도둑).cpp
//  BOJ
//
//  Created by jung on 3/22/24.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long

int N, K;
// 무게 가격
vector<pair<int, int>> arr(300000);
//vector<int> capacity(300000);
multiset<int> capacity;

void input() {
	cin >> N >> K;
	for(int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	
	for(int i = 0; i < K; i++) {
		int num; cin >> num;
		capacity.insert(num);
	}
}

// 가격 내림 차순 && 무게 오름 차순
bool comp(pair<int, int> a, pair<int, int> b) {
	if(a.second == b.second) return a.first < b.first;
	else return a.second > b.second;
}

ll solve() {
	ll result = 0;
	// 가격 순으로 정렬.
	// 이후, 이거를 넘는 처음!
	sort(arr.begin(), arr.end(), comp);
	
	for(int i = 0; i < N; i++) {
		auto iter = capacity.lower_bound(arr[i].first);

		if(iter == capacity.end()) continue;

		capacity.erase(iter);
		result += arr[i].second;
	}
	return result;
}

int main() {
	FAST;
	input();
	cout << solve() << endl;
}
