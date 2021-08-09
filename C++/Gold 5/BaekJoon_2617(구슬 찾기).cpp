#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int ans[100][100]; // i 가 j보다 무거우면 1 가벼우면 -1
int N,M, res;

void FindAns(){
    const int comp = (N+1)/2;

    for(int i = 1; i<=N; i++){
        int lightCnt = 0;
        int heavyCnt = 0;
        for(int j = 1; j<=N; j++){
            if(ans[i][j] == 1) heavyCnt++;
            if(ans[i][j] == -1) lightCnt++;
        }
        if(heavyCnt >= comp || lightCnt >= comp) res++;
    }
}

void Solve(){
    for(int k = 1; k<=N; k++){
        for(int i = 1; i<=N; i++){
            for(int j =1; j<=N; j++){
                if(i == j || ans[i][j] != 0) continue;
                if(ans[i][k] != 0 && ans[i][k] == ans[k][j]){
                    ans[i][j] = ans[i][k];
                    ans[j][i] = -ans[i][k];
                }
            }
        }
    }
}

int main(){
    FAST;
    cin>>N>>M;
    int heavy, light;
    for(int i = 0; i<M; i++){
        cin>>heavy>>light;
        ans[heavy][light] = 1;
        ans[light][heavy] = -1;
    }
    Solve();
    FindAns();
    cout<<res<<endl;
}
