#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N,M;
int invest[301][21];
int dp[301][21];
int trace[301][21];

void Input(){
    cin>>N>>M;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i<N; i++){
        int money;
        cin>>money;
        for(int j = 1; j<=M; j++){
            cin>>invest[money][j];
        }
    }
}

int DP(int idx, int value){
    if(idx > M) return 0;
    
    int &ref = dp[value][idx];
    
    if(ref != -1) return ref;
        
    for(int i = 0; i<=value; i++){
        int comp = DP(idx+1, value - i) + invest[i][idx];
        
        if(ref < comp){
            ref = comp;
            trace[value][idx] = i;
        }
    }
    return ref;
}

void PrintPath(int now, int value){
    if(now > M) return;
    cout<<trace[value][now]<<' ';
    PrintPath(now+1, value - trace[value][now]);
}

int main(){
    FAST;
    Input();
    cout<<DP(1, N)<<endl;
    PrintPath(1,N);
    cout<<endl;
}
