#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 500000
int N,M,ans;
int parent[MMAX];
int level[MMAX];

void Setting(){
    for(int i=0; i<MMAX; i++) parent[i] = i;
}

int getRoot(int x){
    if(x == parent[x]) return x;
    return parent[x] = getRoot(parent[x]);
}

void Union(int a, int b){
    int par_a = getRoot(a);
    int par_b = getRoot(b);
    
    if(level[par_a] < level[par_b]) parent[par_a] = par_b;
    else parent[par_b] = par_a;
    if(level[par_a] == level[par_b]) level[par_a]++;
}

bool sameRoot(int a, int b){
    return getRoot(a) == getRoot(b);
}

bool Solve(int a, int b){
    if(!sameRoot(a, b)){
        Union(a, b);
        return false;
    }
    
    return true;
}

int main(){
    FAST;
    cin>>N>>M;
    Setting();
    
    bool res = false;
    
    int node1,node2;
    for(int i=1; i<=M; i++){
        cin>>node1>>node2;
        if(res) continue;
        res = Solve(node1, node2);
        if(res) ans = i;
    }
    cout<<ans<<'\n';
}
