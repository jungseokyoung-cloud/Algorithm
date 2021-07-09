#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int T,N,M;
int ans[20][10001];
int coin[20];

void Solve(){
    for(int j = 1; j<= M; j++){
        if(j%coin[0] == 0) ans[0][j] = 1;
    }
    
    for(int i = 1; i<N; i++){
        ans[i][0] = 1;
        for(int j = 1; j<=M; j++){
            if(j < coin[i]) ans[i][j] = ans[i-1][j];
            else ans[i][j] = ans[i-1][j] + ans[i][j - coin[i]];
        }
    }
}

int main(){
    FAST;
    cin>>T;
    while(T--){
        memset(ans, 0, sizeof(ans));
        cin>>N;
        for(int i = 0; i<N; i++) cin>>coin[i];
        cin>>M;
        Solve();
        cout<<ans[N-1][M]<<'\n';
    }
}
