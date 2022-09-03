#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long
struct product{
    ll decay, expiration, import;
};

bool comp(int a, int b) {
    return a > b;
}

int N,G,K;
product arr[200001];

void init() {
    cin>>N>>G>>K;
    for(int i = 0; i<N; i++){
        cin>>arr[i].decay>>arr[i].expiration>>arr[i].import;
    }
}

ll calculator(ll x) {
    ll tot = 0;
    vector<ll> canDel;
    for(int i = 0; i<N; i++) {
        ll temp = arr[i].decay * max(1LL, x - arr[i].expiration);
        tot += temp;
        if(arr[i].import == 1) canDel.push_back(temp);
    }
    sort(canDel.begin(), canDel.end(), greater<ll>());
    int Size = min(K, (int)canDel.size());
    
    for(int i = 0; i< Size; i++) tot -= canDel[i];

    return tot;
}

void solve() {
    ll st = 0;
    ll en = 2100000000;
    ll ans = 0;
    
    while(st <= en) {
        ll mid = (st + en) / 2;
        ll temp = calculator(mid);

        if(temp <= G){
            ans = max(ans, mid);
            st = mid + 1;
        }
        else en = mid-1;
    }
    cout<<ans<<endl;
}

int main(){
    FAST;
    init();
    solve();
}
