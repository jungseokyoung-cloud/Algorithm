#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,M;
int weight[101][101];

void Solve(){
    for(int k = 1; k <= N; k++){
        for(int i = 1; i<=N; i++){
            for(int j = 1; j<=N; j++){
                if(i == j || weight[i][j] != 0) continue;
                if(weight[i][k] != 0 && weight[i][k] == weight[k][j]){
                    weight[i][j] = weight[i][k];
                    weight[j][i] = -weight[i][k];
                }
            }
        }
    }
}

void Answer(){
    for(int i = 1; i<=N; i++){
        int sum = 0;
        for(int j = 1; j<=N; j++){
            if(i == j) continue;
            if(weight[i][j] == 0) sum++;
        }
        cout<<sum<<'\n';
    }
}

int main(){
    FAST;
    cin>>N>>M;
    
    int heavy, light;
    for(int i = 0; i < M; i++){
        cin>>heavy>>light;
        weight[heavy][light] = 1;
        weight[light][heavy] = -1;
    }
    Solve();
    Answer();
}
