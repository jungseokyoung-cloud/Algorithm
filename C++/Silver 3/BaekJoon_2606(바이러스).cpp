#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
vector<int> connect[101];
bool vis[101];
int BFS(int start)
{
    int cnt=0;
    queue<int> pos;
    pos.push(start);
    vis[start]=true;;
    while(!pos.empty())
    {
        int x=pos.front();
        pos.pop();
        for(int i=0; i<connect[x].size(); i++)
        {
            int nx=connect[x][i];
            if(vis[nx])continue;
            vis[nx]=true;
            pos.push(nx);
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    FAST;
    int N,M,u,v;
    cin>>N>>M;
    for(int i=0; i<M; i++)
    {
        cin>>u>>v;
        connect[u].push_back(v);
        connect[v].push_back(u);
    }
    cout<<BFS(1)<<'\n';
}
