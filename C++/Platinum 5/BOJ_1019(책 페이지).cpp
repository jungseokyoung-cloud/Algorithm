//
//  BOJ_1019(책 페이지).cpp
//  BOJ
//
//  Created by jung on 4/4/24.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int totalAppearance[10];

void solve(int n) {
	string str = to_string(n);
	
	int apperance = 1;
	int temp = n;
	
	for(int i = 0; i < str.size()-1; i++, apperance*=10) {
		for(int j = 0; j <= 9; j++) {
			int num = temp % 10;
			int cnt = temp / 10;
			
			if(j < num) cnt ++;
			if(j == 0) cnt --;
			if(j == num) totalAppearance[j] += (n % apperance + 1);

			totalAppearance[j] += (cnt * apperance);
		}
		temp /= 10;
	}
	
	int last = str[0] - '0';
	for(int i = 1; i <= last; i++) {
		if(i < last) totalAppearance[i] += (apperance);
		else totalAppearance[i] += (n % apperance + 1);
	}
}

int main() {
	FAST;
	int N; cin >> N;
	solve(N);
	for(int i = 0; i < 10; i++) cout << totalAppearance[i] << " ";
}
