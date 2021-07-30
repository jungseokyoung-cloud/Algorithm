#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,ans = INT_MAX;
int rgb[1000][3];
int color[1000];
int cost[1000][3];

void CheckCost(int start){
    for(int i=0; i<3; i++){
        if(i == start) cost[0][i] = rgb[0][i];
        else cost[0][i] = 100000;
    }
    for(int i=1; i<N; i++){
        for(int j=0; j<3; j++){
            cost[i][j] = min(cost[i-1][(j+1)%3], cost[i-1][(j+2)%3]) + rgb[i][j];
        }
    }
    for(int i=0; i<3; i++){
        if(i==start) continue;
        ans = min(ans, cost[N-1][i]);
    }
}

void Solve(){
    for(int i=0; i<3; i++){
        CheckCost(i);
    }
}

int main(){
    FAST;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>rgb[i][0]>>rgb[i][1]>>rgb[i][2];
    }
    for(int i=0; i<3; i++)   cost[0][i] = rgb[0][i];
    Solve();
    cout<<ans<<'\n';
}
