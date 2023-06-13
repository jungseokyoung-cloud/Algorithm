#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

using namespace std;

int N;
int buildings[51];

void init() {
	cin >> N;
	for(int i = 0 ; i < N; i++) cin >> buildings[i];
}

double getSlope(int x1 ,int y1, int x2, int y2) {
	return double(y2-y1)/(x2-x1);
}

double getYValue(int targetX, double slope, int intercept) {
	return slope * (double)targetX + intercept;
}

int calculateLeftBuildings(int idx) {
	if(idx == 0) return 0;
	
	int result = 1;
	int targetHeight = buildings[idx];
	int nowHeight = buildings[idx-1];
	double slope = getSlope(0, targetHeight, -1, nowHeight);
		
	for(int i = idx-2; i >= 0; i--) {
		nowHeight = buildings[i];
		double temp = getYValue(i-idx, slope, targetHeight);
		
		
		if(temp >= (double)nowHeight) continue;
		result ++;
		slope = getSlope(0, targetHeight, i-idx, nowHeight);
	}
	return result;
}

int calculateRightBuildings(int idx) {
	if(idx == N-1) return 0;
	
	int result = 1;
	int targetHeight = buildings[idx];
	int nowHeight = buildings[idx+1];
	double slope = getSlope(0, targetHeight, 1, nowHeight);
		
	for(int i = idx+2; i < N; i++) {
		nowHeight = buildings[i];
		double temp = getYValue(i-idx, slope, targetHeight);
		
		
		if(temp >= (double)nowHeight) continue;
		result ++;
		slope = getSlope(0, targetHeight, i-idx, nowHeight);
	}
	return result;
}

int solve() {
	int maxResult = 0;
	int idx = 0;
	
	for(int i = 0; i < N; i++) {
		int temp = 0;
		
		temp += calculateLeftBuildings(i);
		temp += calculateRightBuildings(i);
		
		if(maxResult >= temp) continue;
		maxResult = temp;
		idx = i;
	}
	return maxResult;
}

int main() {
	FAST;
	init();
		
	cout << solve() << endl;
}
