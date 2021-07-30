#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 100001
struct Edge{
    int node1, node2, cost;
};
int parent[MMAX];
int cnt;
int level[MMAX];
vector<Edge> edge;
int N,M;
bool compare(Edge a, Edge b){
    return a.cost < b.cost;
}

int getRoot(int x){
    if(x == parent[x]) return x;
    return parent[x] = getRoot(parent[x]);
}

void Union(int a, int b){
    int par_a = getRoot(a);
    int par_b = getRoot(b);
    if(level[par_a] >= level[par_b]) parent[par_b] = par_a;
    else parent[par_a] = par_b;
    if(level[par_a] == level[par_b]) par_a++;
}

bool SameParent(int a, int b){
    return getRoot(a) == getRoot(b);
}

int Solve(){
    int sum = 0;
    for(int i=1; i<=N; i++) parent[i] = i;
    
    for(int i=0; i<edge.size(); i++){
        if(cnt == N-2) break;
        int node1 = edge[i].node1;
        int node2 = edge[i].node2;
        int cost = edge[i].cost;
        if(SameParent(node1, node2)) continue;
        Union(node1, node2);
        sum += cost;
        cnt++;
    }
    
    return sum;
}



int main(){
    FAST;
    cin>>N>>M;
    int node1,node2,cost;
    for(int i=0; i<M; i++){
        cin>>node1>>node2>>cost;
        edge.push_back({node1,node2,cost});
    }
    sort(edge.begin(), edge.end(), compare);
    cout<<Solve()<<'\n';
}
