#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 100001
int V;
bool vis[MMAX];
vector<pair<int, int>> tree [MMAX];
int root,res;

void Input(){
    cin>>V;
    for(int i = 1; i<=V; i++){
        int node;
        cin>>node;
        while(1){
            int node1,cost;
            cin>>node1;
            if(node1 == -1) break;
            cin>>cost;
            tree[node].push_back({node1, cost});
        }
    }
}

void DFS(int node, int cost){
    if(vis[node]) return;
    
    if(res < cost){
        root = node;
        res = cost;
    }
    vis[node] = true;
    
    for(int i = 0; i<tree[node].size(); i++){
        int next = tree[node][i].first;
        int add = tree[node][i].second;
        DFS(next, cost + add);
    }
}

void Solve(){
    DFS(1, 0);
    memset(vis, false, sizeof(vis));
    res = 0;
    DFS(root, 0);
}

int main(){
    FAST;
    Input();
    Solve();
    cout<<res<<'\n';
}
