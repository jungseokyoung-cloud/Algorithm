#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 1001
int N,M,ans;
struct Edge{
    int node1,node2,cost;
};
vector<Edge> graph;
int parent[MMAX];
int level[MMAX];
char gender[MMAX];

bool comp(Edge a, Edge b){
    return a.cost < b.cost;
}

int getRoot(int x){
    if(parent[x] == x) return x;
    return parent[x] = getRoot(parent[x]);
}

void Union(int a, int b){
    int par_a = getRoot(a);
    int par_b = getRoot(b);
    
    if(level[par_a] < level[par_b]) parent[par_a] = par_b;
    else parent[par_b] = par_a;
    
    if(level[par_a] == level[par_b]) level[par_a]++;
}

bool sameParent(int a, int b){
    return getRoot(a) == getRoot(b);
}

bool Solve(){
    sort(graph.begin(), graph.end(), comp);
        
    for(int i = 1; i<=N; i++) parent[i] = i;
    
    for(int i = 0; i<graph.size(); i++){
        int node1 = graph[i].node1;
        int node2 = graph[i].node2;
        int cost = graph[i].cost;
        if(gender[node1] == gender[node2]) continue;
        if(sameParent(node1, node2)) continue;
        Union(node1, node2);
        ans += cost;
    }
    int comp = getRoot(1);
    
    for(int i = 2; i<=N; i++){
        if(getRoot(i) != comp) return false;
    }
    return true;
}

int main(){
    cin>>N>>M;
    
    for(int i = 1; i<=N; i++) cin>>gender[i];
    
    int node1,node2,cost;
    while(M--){
        cin>>node1>>node2>>cost;
        graph.push_back({node1,node2,cost});
    }
    bool res = Solve();
    if(res) cout<<ans<<'\n';
    else cout<<"-1"<<'\n';
}
