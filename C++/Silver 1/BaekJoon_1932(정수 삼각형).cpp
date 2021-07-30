#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int arr[501][501];
int ans[501][501];
int N,res;

void Solve(){
    ans[1][1] = arr[1][1];
    for(int i =1; i<N; i++){
        for(int j = 1; j<=i; j++){
            ans[i+1][j] = max(ans[i+1][j], ans[i][j] + arr[i+1][j]);
            ans[i+1][j+1] = max(ans[i+1][j+1], ans[i][j] + arr[i+1][j+1]);
        }
    }
    
    for(int i = 1; i<=N; i++) res = max(res, ans[N][i]);
}

int main(){
    FAST;
    cin>>N;
    for(int i = 1; i<=N; i++){
        for(int j =1; j<=i; j++){
            cin>>arr[i][j];
        }
    }
    Solve();
    cout<<res<<'\n';
}
