#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
vector<int> connect[1001];
bool vis [1001];
int main()
{
    FAST;
    int N,M,u,v,cnt=0;//N은정점의 개수 M은 간선
    cin>>N>>M;
    for(int i=0; i<M; i++)
    {
        cin>>u>>v;
        connect[u].push_back(v);
        connect[v].push_back(u);
    }
    queue<int> pos;
    for(int i=1; i<=N; i++)
    {
        if(!vis[i])
        {
            pos.push(i);
            cnt++;
            vis[i]=true;
            while(!pos.empty())
            {
                int x=pos.front();
                pos.pop();
                for(int j=0; j<connect[x].size(); j++)
                {
                    int nx=connect[x][j];
                    if(vis[nx])continue;
                    pos.push(nx);
                    vis[nx]=true;
                }
                
            }
        }
    }
    cout<<cnt<<'\n';
}
