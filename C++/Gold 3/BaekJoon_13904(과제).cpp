#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int dp[1001][1001];
pair<int, int> assign[1001];
int N,ans;

void Solve(){
    sort(assign, assign + N + 1);
    for(int i = 1; i<=N; i++){
        int deadline = assign[i].first;
        int value = assign[i].second;
        for(int j = 1; j<=N; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(j > deadline) continue;
            
            dp[i][j] = max(dp[i][j], dp[i-1][j-1] + value);
            ans = max(dp[i][j], ans);
        }
    }
}

int main(){
    FAST;
    cin>>N;
    for(int i = 1; i<=N; i++) cin>>assign[i].first>>assign[i].second;
    Solve();
    cout<<ans<<endl;
}
