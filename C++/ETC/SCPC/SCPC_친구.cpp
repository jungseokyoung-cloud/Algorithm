#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 100001
int T,N,ans;
int parent[MMAX];
int level[MMAX];
bool res[MMAX];

void Setting(){
    for(int i = 1; i<=N; i++) parent[i] = i;
    fill(level, level+MMAX, 0);
    memset(res, false, sizeof(res));
    ans = 0;
}

int getRoot(int x){
    if(parent[x] == x) return x;
    return parent[x] = getRoot(parent[x]);
}

void Union(int a, int b){
    if(b > N) return;
    int par_a = getRoot(a);
    int par_b = getRoot(b);
    
    if(level[par_b] > level[par_a]) parent[par_a] = par_b;
    
    else parent[par_b] = par_a;
    
    if(level[par_a] == level[par_b]) level[par_a] ++;
}

bool SameRoot(int a, int b){
    return getRoot(a) == getRoot(b);
}

void Solve(){
    for(int i = 1; i<=N; i++){
        int par = getRoot(i);
        if(res[par]) continue;
        res[par] = true;
        ans++;
    }
}

int main(){
    FAST;
    cin>>T;
    for(int t = 1; t<=T; t++){
        cin>>N;
        Setting();
        
        int node;
        for(int i = 1; i<=N; i++){
            cin>>node;
            Union(i, node+i);
        }
        Solve();
        cout<<"Case #"<<t<<'\n'<<ans<<'\n';
    }
}
