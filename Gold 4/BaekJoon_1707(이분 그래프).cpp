#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 20001
int V,E;
int vis[MMAX];
vector<int> connect[MMAX];
bool Bipartite_Graph(int start){
    queue<int> q;
    q.push(start);
    vis[start]=1;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=0; i<connect[now].size(); i++){
            int next=connect[now][i];
            if(vis[next]!=0 && vis[next]==vis[now]) return false;
            else if(vis[next]!=0 && vis[next]!=vis[now]) continue;
            vis[next]=-vis[now];
            q.push(next);
        }
    }
    return true;
}
void Clear(){
    fill(vis, vis+MMAX, 0);
    for(int i=1; i<=V; i++){
        connect[i].clear();
    }
}
bool Solve(){
    for(int i=1; i<=V; i++){
        if(vis[i]==0){
        bool ans=Bipartite_Graph(i);
            if(!ans)  return false;
        }
    }
    return true;
}
int main(){
    FAST;
    int T;
    cin>>T;
    while(T--){
        Clear();
                cin>>V>>E;
        int node1,node2;
        for(int i=0; i<E; i++){
            cin>>node1>>node2;
            connect[node1].push_back(node2);
            connect[node2].push_back(node1);
        }
        bool ans=Solve();
        if(ans) cout<<"YES"<<'\n';
        else cout <<"NO"<<'\n';
    }
}
