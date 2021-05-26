#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
vector<int>connect[1001];
bool vis[1001];
void DFS(int start)
{
    vis[start]=true;
    cout<<start<<' ';
    for(int i=0; i<connect[start].size(); i++)
    {
        int nx=connect[start][i];
        if(vis[nx])continue;
        DFS(nx);
    }
}
void BFS(int start)
{
    queue<int> pos;
    pos.push(start);
    vis[start]=true;
    while(!pos.empty())
    {
        int x=pos.front();
        pos.pop();
        cout<<x<<' ';
        for(int i=0; i<connect[x].size(); i++)
        {
            int nx=connect[x][i];
            if(vis[nx])continue;
            pos.push(nx);
            vis[nx]=true;
        }
    }
    cout<<'\n';
}
int main()
{
    FAST;
    int N,M,start,u,v;
    cin>>N>>M>>start;
    for (int i=0; i<M; i++)
    {
        cin>>u>>v;
        connect[u].push_back(v);
        connect[v].push_back(u);
    }
    for(int i=0; i<N; i++)
        sort(connect[i].begin(), connect[i].end());
    DFS(start);
    cout<<'\n';
    memset(vis, false, sizeof(vis));
    BFS(start);
}
