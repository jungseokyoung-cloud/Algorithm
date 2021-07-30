#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,M,res = INT_MAX;
int ans[101][10001]; // i 까지 선택할시 값이 j인 것중 바이트의 최댓값
pair<int, int> APP[101];

void Solve(){
    for(int i = 1; i<=N; i++){
        for(int j = 0; j<=10000; j++){
            int byte = APP[i].first;
            int cost = APP[i].second;
                        
            if(j >= cost)   ans[i][j] = max(ans[i-1][j], ans[i-1][j-cost] + byte);
            else ans[i][j] = ans[i-1][j];
                        
            if(ans[i][j] >= M) res = min(res,j);
        }
    }
}

int main(){
    FAST;
    cin>>N>>M;
    for(int i = 1; i<=N; i++){
        cin>>APP[i].first;
    }
    for(int i = 1; i<=N; i++){
        cin>>APP[i].second;
    }
    
    Solve();
    cout<<res<<'\n';
}
