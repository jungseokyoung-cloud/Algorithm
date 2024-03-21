//
//  BOJ_3343(장미).cpp
//  BOJ
//
//  Created by jung on 3/20/24.
//

#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long

struct FlowerStore {
	ll cnt, price;
};

FlowerStore store1, store2;
ll N;

ll solve() {
	ll result = LLONG_MAX;
	// 같은 개수에서의 가격을 비교 -> 좋은 애를 A에 저장
	if(store1.cnt * store2.price < store2.cnt * store1.price) swap(store1, store2);
	// 2번 가게에서 A개 이상 구매할 필요 X
	for(ll cnt2 = 0; cnt2 < store1.cnt; cnt2++) {
		double temp = ((double)(N- cnt2 * store2.cnt) / store1.cnt);
		ll cnt1 = ceil(temp);
		if(cnt1 < 0) cnt1 = 0;
		
		result = min(result, cnt1 * store1.price + cnt2 * store2.price);
		
		if(cnt1 == 0) break;
	}
	
	return result;
}

int main() {
	FAST;
	cin >> N >> store1.cnt >> store1.price >> store2.cnt >> store2.price;
	
	cout << solve() << endl;
}
