#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long
int T, N;
ll dp[65][10];
ll ans;

void Solve(){
    for(int i = 0; i<10; i++) dp[1][i] = 1;
    
    for(int i = 2; i<=N; i++){
        for(int j = 0; j<10; j++){
            for(int k = 9; k>=j; k--){
                dp[i][j] += dp[i-1][k];
            }
        }
    }
    for(int i = 0; i<10; i++)   ans += dp[N][i];
}

int main(){
    FAST;
    cin>>T;
    while(T--){
        memset(dp, 0, sizeof(dp));
        cin>>N;
        ans = 0;
        Solve();
        cout<<ans<<endl;
    }
}
