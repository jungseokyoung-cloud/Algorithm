#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
const int MMAX = 200001;
int T,F;
int parent[MMAX];
int level[MMAX];

map<string, int> vis;

int getRoot(int x){
    if(parent[x] == x) return x;
    return parent[x] = getRoot(parent[x]);
}

void Union(int a, int b){
    int par_a = getRoot(a);
    int par_b = getRoot(b);
    
    if(level[par_a] < level[par_b]) swap(par_a, par_b);
    parent[par_b] = par_a;
    level[par_a] += level[par_b];
}

void Solve(){
    for(int i = 1; i<MMAX; i++) parent[i] = i;
    fill(level, level + MMAX, 1);
    int idx = 1;
    while(F--){
        string s1,s2;
        cin>>s1>>s2;
        
        if(vis.find(s1) == vis.end()) vis[s1] = idx++;
        if(vis.find(s2) == vis.end()) vis[s2] = idx++;
                
        int par_a = getRoot(vis[s1]);
        int par_b = getRoot(vis[s2]);

        if(par_a != par_b) Union(par_a, par_b);
        cout<<max(level[par_a], level[par_b])<<endl;
    }
}

int main(){
    FAST;
    cin>>T;
    while(T--){
        vis.clear();
        cin>>F;
        Solve();
    }
}
