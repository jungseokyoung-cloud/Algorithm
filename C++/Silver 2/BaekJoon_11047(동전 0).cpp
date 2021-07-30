#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,K;
int ans;
int coin[10];

void Solve(){
    for(int i = N-1; i>=0; i--){
        if(K/coin[i] == 0) continue;
        int temp = K/coin[i];
        K -= temp*coin[i];
        ans += temp;
    }
}

int main(){
    FAST;
    cin>>N>>K;
    
    for(int i = 0; i<N; i++) cin>>coin[i];
    Solve();
    cout<<ans<<'\n';
}
