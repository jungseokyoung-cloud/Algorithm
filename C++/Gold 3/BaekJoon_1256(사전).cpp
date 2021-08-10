#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N,M,K, zCnt, aCnt;
string ans;
int dp[101][101]; //a가 i 개이고 z가 j개일때 경우의 수
bool cantPrint;

void DFS(int n, int m, int k){
    if(n == 0){
        zCnt += m;
        for(int i = 0; i<m; i++) ans.push_back('z');
        return;
    }
    if(m == 0){
        aCnt += n;
        for(int i = 0; i<n; i++) ans.push_back('a');
        return;
    }
    if(dp[n-1][m] >= k){
        aCnt++;
        ans.push_back('a');
        DFS(n-1, m, k);
    }
    else{
        zCnt++;
        ans.push_back('z');
        DFS(n, m-1, k-dp[n-1][m]);
    }
}

void Solve(){
    fill(dp[0], dp[0] + 101, 1);
    for(int i = 1; i<=N; i++){
        dp[i][0] = 1;
        for(int j = 1; j<=M; j++){
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
            if (dp[i][j] > 1000000000) dp[i][j] = 1000000000;
        }
    }
    if(dp[N][M] < K){
        cantPrint = true;
        return;
    }
    DFS(N, M, K);
    if(aCnt < N){
        for(int i = 0; i<N-aCnt; i++) ans.push_back('a');
    }
    if(zCnt < M){
        for(int i = 0; i<M-zCnt; i++) ans.push_back('z');
    }
}

int main(){
    FAST;

    cin>>N>>M>>K;
    Solve();
    if(cantPrint) cout<<"-1"<<endl;
    else cout<<ans<<endl;
}
