#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int MMAX = 100001;
int N,M;
int parent[MMAX][18];
int depth[MMAX];
vector<int> graph [MMAX];

void MakeTree(int now, int par){
    depth[now] = depth[par] + 1;
    
    parent[now][0] = par;
    
    for(int i = 1; i<18; i++){
        
        int tmp = parent[now][i-1];
        if(tmp == -1) continue;
        parent[now][i] = parent[tmp][i-1];
    }
    
    for(int i = 0; i<graph[now].size(); i++){
        int next = graph[now][i];
        if(next == par) continue;
        MakeTree(next, now);
    }
}

int Solve(int a, int b){
    if(depth[a] != depth[b]){ // 둘의 깊이가 같도록 !
        if(depth[a] > depth[b]) swap(a, b); // b의 깊이가 더 깊도록
        
        for(int i = 17; i>=0; i--){
            if(parent[b][i] == -1) continue;
            if(depth[a] <= depth[parent[b][i]]) b = parent[b][i];
        }
    }
    
    if(a != b){
        for(int i = 17; i>=0; i--){
            if(parent[a][i] != parent[b][i]){
                a = parent[a][i];
                b = parent[b][i];
            }
        }
        a = parent[a][0];
    }
    return a;
}

int main(){
    FAST;
    cin>>N;
    int node1,node2;
    
    memset(parent, -1, sizeof(parent));
    memset(depth, -1, sizeof(depth));
    
    for(int i = 0; i<N-1; i++){
        cin>>node1>>node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    MakeTree(1, 0);
    cin>>M;
    while(M--){
        cin>>node1>>node2;
        cout<<Solve(node1, node2)<<'\n';
    }
}
