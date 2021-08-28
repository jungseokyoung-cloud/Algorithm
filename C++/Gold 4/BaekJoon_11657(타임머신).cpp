#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
const int INF = INT_MAX;
int N,M;
bool isCycle;
long long dist[501];
vector<pair<int, int>> graph[501];

void Solve(){
    for(int temp = 0; temp < N; temp++){
        for(int now = 1; now<=N; now++){
            if(dist[now] == INF) continue;
            for(int i = 0; i<graph[now].size(); i++){
                int next = graph[now][i].first;
                if(dist[next] > dist[now] + graph[now][i].second){
                    dist[next] = dist[now] + graph[now][i].second;
                    
                    if(temp == N-1){
                        isCycle = true;
                        return;
                    }
                }
            }
        }
    }
}

void Print(){
    if(isCycle) cout<<"-1"<<endl;
    else{
        for(int i = 2; i<=N; i++){
            if(dist[i] == INF) cout<<"-1"<<endl;
            else cout<<dist[i]<<endl;
        }
    }
}

int main(){
    FAST;
    cin>>N>>M;
    fill(dist, dist + 501, INF);
    dist[1] = 0;
    while(M--){
        int node1,node2,cost;
        cin>>node1>>node2>>cost;
        graph[node1].push_back({node2,cost});
        
    }
    Solve();
    Print();
}
