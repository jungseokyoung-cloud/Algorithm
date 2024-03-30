//
//  BOJ_1654(랜선 자르기).cpp
//  BOJ
//
//  Created by jung on 3/22/24.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

#define ll long long

ll N, K;
ll maxLen = -1200;
ll arr[10010];

void input() {
	cin >> K >> N;
	for(int i = 0; i < K; i++) {
		cin >> arr[i];
		maxLen = maxLen > arr[i] ? maxLen : arr[i];
	}
}

long long getCnt(long long len) {
	long long result = 0;
	for(int i = 0; i < K; i++) result += arr[i]/len;
	
	return result;
}

// uppder_bound
int solve() {
	// [1, 2^31)
	long long st = 1, en = maxLen + 1;
	
	while(st < en) {
		long long mid = (st + en) / 2;
		
		// 갯수가 더 적거나 작으면, 길이 줄어야 함.
		if(getCnt(mid) < N) en = mid;
		// 갯수가 같거나 작다먄, 줄여도 ㄱㅊ
		else st = mid + 1;
	}
	return (int)en - 1;
}

int main(){
	input();
	cout << solve() << '\n';
}

/*
// 랜선의 길이 ->
 랜선의 길이 길어질 수록, 만들 수 있는 랜선의 갯수 줄어듬.
 그 중 최대 길이
*/


/*				en	st
 111111 2222 33333
 */
