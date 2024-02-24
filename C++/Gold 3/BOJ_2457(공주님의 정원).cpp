//
//  BOJ_.cpp
//  BOJ
//
//  Created by jung on 2/23/24.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

struct Date {
	int month = 0, day = 0;
};

int N;
vector<pair<Date, Date>> arr;

bool compareDate(Date a, Date b) {
	if(a.month == b.month) return a.day < b.day;
	return a.month < b.month;
}

bool compare1(pair<Date, Date> a, pair<Date, Date> b) {
	return compareDate(a.first, b.first);
}

bool compare2(pair<Date, Date> a, pair<Date, Date> b) {
	return compareDate(a.second, b.second);
}

void input() {
	cin >> N;
	
	Date date1, date2;
	for(int i = 0; i < N; i++) {
		cin >> date1.month >> date1.day >> date2.month >> date2.day;
		arr.push_back({date1, date2});
	}
}

bool isFinish(Date &a) {
	Date temp;
	temp.month = 11;
	temp.day = 30;
	
	return compareDate(temp, a);
}

int solve() {
	sort(arr.begin(), arr.end(), compare1);
	
	vector<pair<Date, Date>> temp;
	
	Date currentDate;
	currentDate.month = 3; currentDate.day = 1;
	int index = 0;
	int cnt = 0;
	while(index < N) {
		if(isFinish(currentDate)) return cnt;

		while(index < N && !compareDate(currentDate, arr[index].first)) {
			temp.push_back(arr[index ++]);
		}

		if(temp.size() == 0) return 0;
		sort(temp.begin(), temp.end(), compare2);
		currentDate = temp[temp.size()-1].second;
		cnt++;
		
		temp.clear();
	}

	if(!isFinish(currentDate)) return 0;
	return cnt;
}

int main() {
	FAST;
	input();
	cout << solve() << endl;
}
