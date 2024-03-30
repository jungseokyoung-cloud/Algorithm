//
//  BOJ_3151(합이 0).cpp
//  BOJ
//
//  Created by jung on 3/30/24.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long

int N;
int arr[10001]; 

void input() {
	cin >> N;
	for(int i = 0; i < N; i++) cin >> arr[i];
}

ll solve() {
	ll result = 0;
	sort(arr, arr + N);
	
	for(int i = 0; i < N; i++) {
		for(int j = i + 1; j < N; j++) {
			int target = arr[i] + arr[j];
			
			// [lower, upper)
			int upper = (int)(upper_bound(arr+j+1, arr + N, -target) - arr);
			int lower = (int)(lower_bound(arr+j+1, arr + N, -target) - arr);
			
			int temp = upper - lower;
			if(i >= lower && i < upper) temp --;
			if(j >= lower && j < upper) temp --;
			
			if(temp <= 0) continue;

			result += temp;
		}
	}
		return result ;
}

int main() {
	FAST;
	input();
	cout << solve() << endl;
}
