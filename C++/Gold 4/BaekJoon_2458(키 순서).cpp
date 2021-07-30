#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int height[501][501];
int N,M,cnt;

void Check(){
    for(int i = 1; i<=N; i++){
        bool res = true;
        for(int j = 1; j<=N; j++){
            if(height[i][j] != 0 || i == j) continue;
            res = false;
            break;
        }
        if(res) cnt++;
    }
}

void Solve(){
    for(int k = 1; k <=N; k++){
        for(int i = 1; i<=N; i++){
            for(int j = 1; j<=N; j++){
                if(height[i][j] != 0 || i == j) continue;
                if(height[i][k] != 0 && height[i][k] == height[k][j]){
                    height[i][j] = height[i][k];
                    height[j][i] = height[i][k]*-1;
                    
                }
            }
        }
    }
}

int main(){
    cin>>N>>M;
    int small, tall;
    while(M--){
        cin>>small>>tall;
        height[small][tall] = 1;
        height[tall][small] = -1;
    }
    Solve();
    Check();
    cout<<cnt<<'\n';
}
