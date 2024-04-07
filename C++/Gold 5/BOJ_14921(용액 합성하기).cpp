//
//  BOJ_14921(용액 합성하기).cpp
//  BOJ
//
//  Created by jung on 4/7/24.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int N;
vector<int> arr;

void input() {
	cin >> N;
	
	int num;
	for(int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}
}

int getMinValue(int idx, int tempIdx) {
	if(tempIdx == N) tempIdx --;
	if(tempIdx == idx) tempIdx --;
	if(tempIdx < 0) return 2e8;
	
	int result = 0;
	result = arr[idx] + arr[tempIdx];

	if(tempIdx > 0 && tempIdx-1 != idx) {
		int temp = arr[idx] + arr[tempIdx-1];
		result = abs(result) > abs(temp) ? temp : result;
	}
	
	return result;
}

int solve() {
	int result = 2e8 + 1;
	
	sort(arr.begin(), arr.end());
	
	for(int i = 0; i < N; i++) {
		int target = -arr[i];
		int idx = (int)(lower_bound(arr.begin()+i+1, arr.end(), target) - arr.begin());
		int temp = getMinValue(i, idx);
		result = abs(result) > abs(temp) ? temp : result;
	}
	
	return result;
}

int main() {
	input();
	cout << solve() << endl;
}
