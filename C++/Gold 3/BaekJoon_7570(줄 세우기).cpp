#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N,ans;
int dp[1000001];
void Solve(){
    int num;
    for(int i = 0; i<N; i++){
        cin>>num;
        dp[num] = dp[num - 1] + 1;
        ans = max(ans, dp[num]);
    }
}

int main(){
    FAST;
    cin>>N;
    Solve();
    cout<<N-ans<<endl;
}
