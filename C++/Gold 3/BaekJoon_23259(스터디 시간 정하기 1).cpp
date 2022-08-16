#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long
int N, T;
ll timeArr[100001];
ll tot[100001];

void init() {
    cin>>N>>T;
    for(int i = 0; i<N; i++){
        int K;
        cin>>K;
        for(int j = 0; j<K; j++){
            int st, en;
            cin>>st>>en;
            timeArr[st] ++;
            timeArr[en] --;
        }
    }
}

void solve() {
    for(int i = 1; i < 100001; i++) timeArr[i] += timeArr[i-1];
    tot[0] = timeArr[0];
    
    for(int i = 1; i < 100001; i++) tot[i] = tot[i-1] + timeArr[i];
    
    
    ll comp = tot[T-1];
    int ans = T;
    for(int i = T; i < 100001; i++) {
        ll temp = tot[i] - tot[i-T];
        
        if(temp > comp){
            comp = temp;
            ans = i+1;
        }
    }
    cout<<ans-T<<' '<<ans<<endl;
}

int main(){
    FAST;
    init();
    solve();
}
