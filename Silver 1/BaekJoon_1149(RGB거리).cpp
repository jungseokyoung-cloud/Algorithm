#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int INF = INT_MAX;
int N;
int res = INF;
int arr[1000][3];
int ans[1000][3];

void Solve(){
    for(int i = 0; i<3; i++) ans[0][i] = arr[0][i];
    
    
    for(int i = 1; i<N; i++){
        for(int j = 0; j<3; j++){
            ans[i][j] = min(ans[i-1][(j+1)%3], ans[i-1][(j+2)%3]) + arr[i][j];
        }
    }
    
    for(int i = 0; i<3; i++) res = min(res, ans[N-1][i]);
}

int main(){
    FAST;
    cin>>N;
    for(int i = 0; i<N; i++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    Solve();
    cout<<res<<'\n';
}
