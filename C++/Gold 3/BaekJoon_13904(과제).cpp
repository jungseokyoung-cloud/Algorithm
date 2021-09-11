#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N, ans;
pair<int, int> assign[1000];
int dp[1001][1001];

void Solve(){
    sort(assign, assign+N);
    
    for(int i = 0; i<N; i++){
        int day = assign[i].first;
        int cost = assign[i].second;
        
        for(int j = 1; j<=day; j++){
            if(i == 0) dp[i][j] = cost;
            else  dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + cost);
            ans = max(ans, dp[i][j]);
        }
    }
}

int main(){
    FAST;
    cin>>N;
    for(int i = 0; i<N; i++){
        cin>>assign[i].first>>assign[i].second;
    }
    Solve();
    cout<<ans<<endl;
}
