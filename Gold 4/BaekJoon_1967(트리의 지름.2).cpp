#include <iostream>
#include<algorithm>
#include<vector>
#include <utility>
#include<cstring>
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 10001
using namespace std;
vector<pair<int, int>> connect[MMAX];
bool vis[MMAX];
int diameter,N,ans;

void DFS(int node, int total){
    if(vis[node]) return;
    vis[node]=true;
    if(ans<total){
        ans=total;
        diameter=node;
    }
    
    for(int i=0; i<connect[node].size(); i++){
        int next=connect[node][i].first;
        int cost=connect[node][i].second;
        DFS(next, total+cost);
    }
}

int main(){
    FAST;
    cin>>N;
    int parent,child,cost;
    for(int i=1; i<N; i++){
        cin>>parent>>child>>cost;
        connect[parent].push_back({child, cost});
        connect[child].push_back({parent, cost});
    }
    DFS(1, 0);
    memset(vis, false, sizeof(vis));
    DFS(diameter, 0);
    cout<<ans<<'\n';
}
