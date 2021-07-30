#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int history[401][401];
int N,K,S;

void Solve(){
    for(int k = 1; k <= N; k++){
        for(int i = 1; i<=N; i++){
            for(int j = 1; j<=N; j++){
                if(i == j || history[i][j] != 0) continue;
                if(history[i][k] != 0 && history[i][k] == history[k][j]){
                    history[i][j] = history[i][k];
                    history[j][i] = -history[i][k];
                }
            }
        }
    }
}

int main(){
    FAST;
    cin>>N>>K;
    
    int node1,node2;
    while(K--){
        cin>>node1>>node2;
        history[node1][node2] = -1;
        history[node2][node1] = 1;
    }
    Solve();
    cin>>S;
    while (S--) {
        cin>>node1>>node2;
        cout<<history[node1][node2]<<'\n';
    }
}
