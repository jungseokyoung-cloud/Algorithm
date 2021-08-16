#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N,M,total;
int invest[301][21];
int dp[301][21];
int path[301][21];

void Input(){
    cin>>N>>M;
    for(int i = 1; i<=N; i++){
        int idx;
        cin>>idx;
        for(int j = 1; j<=M; j++){
            cin>>invest[idx][j];
        }
    }
    memset(dp, -1, sizeof(dp));
}



int Solve(int value, int now){
    int &ref = dp[value][now];
    
    if(now == 0) return 0;
    
    if(ref != -1) return ref;
    
    for(int i = 0; i<=value; i++){
        int res = Solve(i, now-1) + invest[value-i][now];
        if(res > ref){
            ref = res;
            path[value][now] = value-i;
        }
    }
    
    return ref;
}

void Print(int value, int now){
    if(now == 0) return;
    Print(value - path[value][now], now-1);
    cout<<path[value][now]<<' ';
}

int main(){
    FAST;
    Input();
    cout<<Solve(N, M)<<endl;
    Print(N,M);
    cout<<endl;
}
