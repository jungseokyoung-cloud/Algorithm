#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long
int parent[10001];
int cost[10001];
int N,M,K,ans;
bool isChoice[10001];

int GetRoot(int x){
    if(parent[x] == x) return x;
    return parent[x] = GetRoot(parent[x]);
}

void Union(int a, int b){
    int par_a = GetRoot(a);
    int par_b = GetRoot(b);

    if(cost[par_a] <= cost[par_b])  parent[par_b] = par_a; // 비용이 더 낮은애를 부모로!
    else  parent[par_a] = par_b;
}

void Solve(){
    for(int i = 1; i<=N; i++) parent[i] = i;
    
    int node1,node2;
    while(M--){
        cin>>node1>>node2;
        Union(node1, node2);
    }
    for(int i = 1; i<=N; i++){
        int par = GetRoot(i);
        if(isChoice[par]) continue;
        isChoice[par] = true;
        ans += cost[par];
    }
}


int main(){
    FAST;
    cin>>N>>M>>K;
    for(int i = 1; i<=N; i++) cin>>cost[i];
    Solve();
    if(ans > K) cout<<"Oh no"<<endl;
    else cout<<ans<<endl;
}
