#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
struct Edge{
    int node1,node2,cost;
};
int V,E,sum;
vector<Edge> edge;
vector<int> parent(10001);

int Find_Root(int x){
    if(parent[x]==x) return x;
    return parent[x]=Find_Root(parent[x]);
}

void UnionRoot(int par_a, int par_b){
    if(par_a<par_b) parent[par_b]=par_a;
    else parent[par_a]=par_b;
}

bool compare(int a, int b){
    int par_a=Find_Root(a);
    int par_b=Find_Root(b);
    if(par_a==par_b) return true;
    else  return false;
}
bool comp(Edge a, Edge b){
    return a.cost<b.cost;
}
void Solve(){
    sort(edge.begin(), edge.end(), comp);
    
    for(int i=1; i<=V; i++)
    parent[i]=i;
    for(int i=0; i<E; i++){
        int par_a=Find_Root(edge[i].node1);
        int par_b=Find_Root(edge[i].node2);
        if(par_a!=par_b){
            UnionRoot(par_a, par_b);
            sum+=edge[i].cost;
        }
    }
}
int main(){
    FAST;
    cin>>V>>E;
    int A,B,C;
    for(int i=0; i<E; i++){
        cin>>A>>B>>C;
        edge.push_back({A,B,C});
    }
    Solve();
    cout<<sum<<'\n';
}
