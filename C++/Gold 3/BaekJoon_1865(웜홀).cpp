#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
const int INF = INT_MAX;
int T,N,M,W;
bool isCycle;
vector<pair<int, int>> graph[502];
int dist[502];

void Setting(){
    for(int i = 0; i<=500; i++) graph[i].clear();
    fill(dist, dist+501, INF);
    dist[0] = 0;
    isCycle = false;
}
void Input(){
    cin>>N>>M>>W;
    
    int node1,node2,cost;
    for(int i = 0; i<M; i++){
        cin>>node1>>node2>>cost;
        graph[node1].push_back({node2, cost});
        graph[node2].push_back({node1, cost});
    }
    for(int i = 0; i<W; i++){
        cin>>node1>>node2>>cost;
        graph[node1].push_back({node2,-cost});
    }
    for(int i = 1; i<=N; i++)   graph[0].push_back({i,0}); // 임의의 정점
}

void Solve(){
    for(int temp = 0; temp<N; temp++){
        
        for(int now = 0; now<=N; now++){
            if(dist[now] == INF) continue;
            
            for(int i = 0; i<graph[now].size(); i++){
                int next = graph[now][i].first;
                int add = graph[now][i].second;
                if(dist[next] > dist[now] + add){
                    dist[next] = dist[now] + add;
                    if(temp == N-1){
                        isCycle = true;
                        return;
                    }
                }
            }
        }
    }
}

int main(){
    FAST;
    cin>>T;
    while(T--){
        Setting();
        Input();
        Solve();
        if(isCycle) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
