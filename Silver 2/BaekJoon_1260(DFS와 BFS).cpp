#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int N,M,V;
vector<int> graph[1001];
bool vis[1001];
vector<int> ansBFS, ansDFS;

void DFS(int node){
    if(vis[node]) return;
    
    vis[node] = true;
    ansDFS.push_back(node);
    
    for(int i = 0; i<graph[node].size(); i++){
        int next = graph[node][i];
        DFS(next);
    }
}

void BFS(){
    queue<int> node;
    node.push(V);
    vis[V] = true;
    
    while(!node.empty()){
        int now = node.front();
        node.pop();
        ansBFS.push_back(now);
        
        for(int i = 0; i<graph[now].size(); i++){
            int next = graph[now][i];
            
            if(vis[next]) continue;
            
            vis[next] = true;
            node.push(next);
        }
    }
}

void Solve(){
    for(int i = 1; i<=N; i++) sort(graph[i].begin(), graph[i].end());
    DFS(V);
    memset(vis, false, sizeof(vis));
    BFS();
}

void Print(){
    for(auto res : ansDFS) cout<<res<<' ';
    cout<<'\n';
    for(auto res : ansBFS) cout<<res<<' ';
    cout<<'\n';
}

int main(){
    FAST;
    cin>>N>>M>>V;
    int node1,node2;
    while(M--){
        cin>>node1>>node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    Solve();
    Print();
}
