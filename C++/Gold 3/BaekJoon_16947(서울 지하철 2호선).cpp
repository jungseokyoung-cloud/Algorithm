#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N;
vector<int>metro[3001];
int dis[3001];
bool vis[3001];
bool vis2[3001];
int par[3001];
queue<int> node;

void CheckCycle(int now, int next){
    dis[next] = 0;
    node.push(next);
    vis2[next] = true;
    while(now != next){
        node.push(now);
        vis2[now] = true;
        dis[now] = 0;
        now = par[now];
    }
}

void DFS(int now){
    
    vis[now] = true;
    
    for(int i = 0; i<metro[now].size(); i++){
        int next = metro[now][i];
        if(par[now] == next) continue;
        if(vis[next] && dis[now] == -1) CheckCycle(now, next);
        
        if(!vis[next]){
            par[next] = now;
            DFS(next);
        }
    }
}

void BFS(){
    while(!node.empty()){
        int now = node.front();
        node.pop();
        
        for(int i = 0; i<metro[now].size(); i++){
            int next = metro[now][i];
            if(vis2[next]) continue;
            node.push(next);
            vis2[next] = true;
            dis[next] = dis[now] + 1;
        }
    }
}

void Solve(){
    DFS(1);
    BFS();
    for(int i = 1; i<=N; i++){
        cout<<dis[i]<<' ';
    }
    cout<<endl;
}

int main(){
    FAST;
    fill(dis, dis+3001, -1);
    cin>>N;
    for(int i = 0; i<N; i++){
        int node1,node2;
        cin>>node1>>node2;
        metro[node1].push_back(node2);
        metro[node2].push_back(node1);
    }
    Solve();
}
