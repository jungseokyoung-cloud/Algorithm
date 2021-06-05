#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,M;
vector<int> parent;
int getRoot(int x){
    if(parent[x]==x) return x;
    return parent[x]=getRoot(parent[x]);
}

bool Find(int a, int b){
    int par_a=getRoot(a);
    int par_b=getRoot(b);
    return par_a == par_b;
}

void Union(int a, int b){
    int par_a=getRoot(a);
    int par_b=getRoot(b);
    if(par_a<par_b) parent[par_b]=par_a;
    else parent[par_a]=par_b;
}
void Solve(int a, int node1, int node2){
    if(a==0) Union(node1, node2);
    else{
        bool ans=Find(node1, node2);
        if(ans) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
            }
}
int main(){
    FAST;
    cin>>N>>M;
    for(int i=0; i<=N; i++)
    parent.push_back(i);
    
    int a,n1,n2;
    while(M--){
        cin>>a>>n1>>n2;
        Solve(a, n1, n2);
    }
}
