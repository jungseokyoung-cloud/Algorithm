#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N,M;
int weight[30];
int marble[8];
bool dp[31][15001];

void checkWeight(int idx, int value){
    if(idx == N) dp[idx][value] = true;
    if(dp[idx][value]) return;
    
    dp[idx][value] = true;
    
    checkWeight(idx + 1, value);
    checkWeight(idx + 1, value + weight[idx]);
    checkWeight(idx + 1, abs(value - weight[idx]));
}

void Input(){
    cin>>N;
    for(int i = 0; i<N; i++){
        cin>>weight[i];
    }
    cin>>M;
    for(int i = 0; i<M; i++){
        cin>>marble[i];
    }
}

int main(){
    FAST;
    Input();
    checkWeight(0, 0);
    for(int i = 0; i<M; i++){
        if(marble[i] > 15000) cout<<"N"<<' ';
        else if(dp[N][marble[i]]) cout<<"Y"<<' ';
        else cout<<"N"<<' ';
    }
}
