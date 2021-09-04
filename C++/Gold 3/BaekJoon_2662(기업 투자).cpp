#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int invest[301][21];
int path[301][21];
int dp[301][21];
int N,M;

void Input(){
    memset(dp, -1, sizeof(dp));
    cin>>N>>M;
    for(int i = 1; i<=N; i++){
        int value;
        cin>>value;
        for(int j = 1; j<=M; j++){
            cin>>invest[i][j];
        }
    }
}

int Solve(int value, int now){
    int &ref = dp[value][now];
    
    if(now == M+1 || value == 0) return 0;
    if(ref != -1) return ref;
    
    for(int i = 0; i<=value; i++){
        int temp = Solve(value-i, now + 1) + invest[i][now];
        
        if(temp > ref) {
            ref = temp;
            path[value][now] = value-i;
        }
    }
    return ref;
}

void Print(int value, int now){
    if(now == M + 1) return;
    
    int cost = value - path[value][now];
    cout<<cost<<' ';
    Print(path[value][now], now+1);
}

int main(){
    FAST;
    Input();
    cout<<Solve(N, 1)<<endl;
    Print(N, 1);
    cout<<endl;
}
