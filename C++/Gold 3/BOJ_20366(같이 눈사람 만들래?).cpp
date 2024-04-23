//
//  BOJ_20366(같이 눈사람 만들래?).cpp
//  BOJ
//
//  Created by jung on 4/23/24.
//

#include <iostream>
#include <algorithm>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N;
int arr[601];

void input() {
	cin >> N;
	for(int i = 0; i < N; i++) cin >> arr[i];
}

int solve1() {
	int result = 0x3f3f3f3f;
	sort(arr, arr+N);
	
	for(int i = 0; i < N; i++) {
		for(int j = i + 2; j < N; j++) {
			int temp = arr[i] + arr[j];
			
			int st = i + 1, en = j-1;
			
			while(st < en) {
				int temp2 = arr[st] + arr[en];
				result = min(result, abs(temp - temp2));
				if(temp2 > temp) en--;
				else st++;
			}
		}
	}
	return result;
}

int solve() {
	int result = 0x3f3f3f3f;
	sort(arr, arr+N);
	
	for(int i = 0; i < N; i++) {
		for(int j = i + 2; j < N; j++) {
			int temp = arr[i] + arr[j];
			
			int en = j - 1;
			for(int st = i + 1; st < N; st++) {
				int temp2 = arr[st] + arr[en];
				if(st < en) result = min(abs(temp - temp2), result);

				while(en > st && (temp2 > temp)) {
					temp2 = arr[st] + arr[--en];
					if(st < en) result = min(abs(temp - temp2), result);
				}
			}
		}
	}
	
	return result;
}

int main() {
	FAST;
	input();
	cout << solve() << endl;
}
