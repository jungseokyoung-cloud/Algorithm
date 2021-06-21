#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int parent[201];
int N,M;
bool canTravel;
vector<int> travel;

int GetRoot(int x){
    if(x == parent[x]) return x;
    return parent[x] = GetRoot(parent[x]);
}

void Union(int a, int b){
    int par_a = GetRoot(a);
    int par_b = GetRoot(b);
    if(par_a < par_b)  parent[par_b] = par_a;
    else parent[par_a] = par_b;
}

bool SameParent(int a , int b){
    return GetRoot(a) == GetRoot(b);
}

void Solve(){
    for(int i=1; i<travel.size(); i++){
        if(!SameParent(travel[i-1], travel[i]))  return;
    }
    canTravel = true;
}

int main(){
    FAST;
    cin>>N>>M;
    int a;
    for(int i=1; i<=N; i++){
        parent[i] = i;
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>a;
            if(a == 1)  Union(i, j);
        }
    }
    for(int i=0; i<M; i++){
        cin>>a;
        travel.push_back(a);
    }
    Solve();
    if(canTravel) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
}
