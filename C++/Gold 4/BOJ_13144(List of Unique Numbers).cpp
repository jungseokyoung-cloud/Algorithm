//
//  BOJ_13144(List of Unique Numbers).cpp
//  BOJ
//
//  Created by jung on 3/19/24.
//

#include <iostream>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ull unsigned long long

int N;
int arr[100001];
bool isSelected[100001] = {false, };

void input() {
	cin >> N;
	for(int i = 0; i < N; i++) cin >> arr[i];
}

ull solve() {
	ull cnt = 0;
	int en = 1;
	isSelected[arr[0]] = true;
	
	for(int st = 0; st < N; st ++) {
		while(en < N) {
			int num = arr[en];
			if(isSelected[num]) break;
			
			isSelected[num] = true;
			en ++;
		}
		
		cnt += (en - st);
		isSelected[arr[st]] = false;
	}
	
	return cnt;
}

int main() {
	FAST;
	
	input();
	cout << solve() << endl;
}
