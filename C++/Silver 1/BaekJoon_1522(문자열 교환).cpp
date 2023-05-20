#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

string str;

void init() {
	cin >> str;
}

int solve() {
	int result, temp = 0;
	int aCount = 0;
	int strLen = (int)str.size();
	
	for(int i = 0; i < strLen; i++) {
		if(str[i] == 'a') aCount ++;
	}
	
	for(int i = 0; i < aCount; i++) {
		if(str[i] == 'b') temp ++;
	}
	result = temp;
	
	for(int i = 0; i < strLen -1; i++) {
		if(str[i] == 'b') temp --;
		if(str[(i + aCount) % strLen] == 'b') temp ++;
		result = min(result, temp);
	}
	
	return result;
}

int main() {
	FAST;
	init();
	cout << solve() << endl;
}
