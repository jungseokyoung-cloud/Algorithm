#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 100001

vector<pair<int, int>> graph[MMAX];
int ans[MMAX];
int N,M,st,en;

void Solve(){
    priority_queue<pair<int, int>> node;
    node.push({0,st});
    
    while(!node.empty()){
        int cost = node.top().first;
        int now = node.top().second;
        node.pop();
        if(cost < ans[now]) continue;
        
        for(int i = 0; i<graph[now].size(); i++){
            int next = graph[now][i].first;
            int ncost = graph[now][i].second;
            int comp = ncost;
            if(cost != 0) comp = min(comp, cost);
            
            if(ans[next] < comp){
                ans[next] = comp;
                node.push({ans[next],next});
            }
        }
        
    }
}

int main(){
    FAST;
    cin>>N>>M;
    while(M--){
        int node1,node2,cost;
        cin>>node1>>node2>>cost;
        graph[node1].push_back({node2,cost});
        graph[node2].push_back({node1,cost});
    }
    cin>>st>>en;
    Solve();
    cout<<ans[en]<<'\n';
}
