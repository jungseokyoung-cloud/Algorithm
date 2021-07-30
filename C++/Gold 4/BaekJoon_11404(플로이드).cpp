#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define INF 10000000
int N,M;
int cost[101][101];

void Solve(){
    for(int n=1; n<=N; n++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(cost[i][j] > cost[i][n] + cost[n][j]){
                    cost[i][j] = cost[i][n] + cost[n][j];
                }
            }
        }
    }    
}

int main(){
    FAST;
    cin>>N>>M;
    for(int i=1; i<=N; i++) {
        fill(cost[i], cost[i]+N+1, INF);
        cost[i][i] = 0;
    }
   
    int start, end, cost1;
    while(M--){
        cin>>start>>end>>cost1;
        cost[start][end] = min(cost1, cost[start][end]);
    }
    Solve();
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(cost[i][j] == INF) cout<<"0"<<' ';
            else    cout<<cost[i][j]<<' ';
        }
        cout<<'\n';
    }
}
