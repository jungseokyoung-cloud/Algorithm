//
//  BOJ_1790(수 이어 쓰기 2).cpp
//  BOJ
//
//  Created by jung on 3/20/24.
//


#include <iostream>
#include <string>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long

int N, K;

void input() {
	cin >> N >> K;
}

int getLength(int num) {
	int len = 0;
	// i는 자릿수를 의미
	for(int st = 1, i = 1; st <= num; st *= 10, ++i) {
		// 각 자릿수 별로 최대 숫자를 의미!
		int en = st * 10 - 1;
		if(en > num) en = num;
		// 모든 수의 갯수 * 자릿수 = 수의 길이
		len += (en - st + 1) * i;
	}

	return len;
}

int getResult(int number) {
	string str = to_string(number);
	
	int len = getLength(number);
	// len 이상인 가장 처음 숫자  (즉, 항상 len >= k를 만족)
	// 즉, (len - k) 만큼 더 나아간것으로
	// 즉, 현재 마지막 위치에서 len-K를 뺴주어야 함!

	int cursor = (int)str.size() - (len - K) - 1;
	return str[cursor] - '0';
}

int solve() {
	int st = 1, en = N+1;
	
	while(st < en) {
		int mid = (st + en) / 2;
		int temp = getLength(mid);
		
		if(temp >= K) en = mid;
		else st = mid + 1;
	}

	if(en == N + 1) return -1;
	else return getResult(en);
}

int main() {
	FAST;
	input();
	cout << solve() << endl;
}
