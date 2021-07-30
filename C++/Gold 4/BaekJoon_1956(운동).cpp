#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int V,E;
const int INF = INT_MAX;
int arr[401][401];
int res = INF;

void Answer(){
    for(int i=1; i<=V; i++){
        int comp = INF;
        for(int k=1; k<=V; k++){
            if(i == k) continue;
            if(arr[i][k] == INF || arr[k][i] ==INF) continue;
            comp = min(comp, arr[i][k] + arr[k][i]);
        }
        res = min(res, comp);
    }
    if(res == INF) res = -1;
}

void Solve(){
    for(int k = 1; k<=V; k++){
        for(int i = 1; i<=V; i++){
            for(int j = 1; j<=V; j++){
                if(arr[i][k] == INF || arr[k][j] == INF) continue;
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
    Answer();
}

int main(){
    FAST;
    
    cin>>V>>E;
    
    for(int i=1; i<=V; i++){
        fill(arr[i], arr[i]+V+1, INF);
    }
    
    int start,end, cost;
    for(int i=0; i<E; i++){
        cin>>start>>end>>cost;
        arr[start][end] = cost;
    }
    Solve();
    cout<<res<<'\n';
}
