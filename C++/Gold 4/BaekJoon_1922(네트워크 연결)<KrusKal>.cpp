#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
struct Edge{
    int node1,node2,cost;
};
bool comp(Edge a, Edge b){
    return a.cost<b.cost;
}
vector<int> parent(1001);
vector<Edge> edge;
int V,E,ans;

int FindRoot(int x){
    if(x==parent[x]) return x;
    return parent[x]=FindRoot(parent[x]);
}
void Union(int a, int b){
    int par_a=FindRoot(a);
    int par_b=FindRoot(b);
    if(par_a<par_b) parent[par_b]=par_a;
    else parent[par_a]=par_b;
}
bool Find(int a, int b){
    return FindRoot(a)==FindRoot(b);
}
void Solve(){
    sort(edge.begin(), edge.end(), comp);
    
    for(int i=1; i<=V; i++)
    parent[i]=i;
    
    for(int i=0; i<edge.size(); i++){
        if(Find(edge[i].node1, edge[i].node2)) continue;
        Union(edge[i].node1, edge[i].node2);
        ans+=edge[i].cost;
    }
}
int main(){
    FAST;
    cin>>V>>E;
    int a,b,c;
    for(int i=0; i<E; i++){
        cin>>a>>b>>c;
        edge.push_back({a,b,c});
    }
    Solve();
    cout<<ans<<'\n';
}
