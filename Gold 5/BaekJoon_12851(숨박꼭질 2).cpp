#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 100001
int vis[MMAX];
int N,K,cnt,Time;
int Move(int i, int x)
{
    if(i==0)
        return x-1;
    else if(i==1)
        return x+1;
    else
        return x+x;
}
void BFS()
{
    queue<int>pos;
    pos.push(N);
    vis[N]=0;
    while(!pos.empty())
    {
        int x=pos.front();
        pos.pop();
        if(x==K)
        {
            cnt++;
        }
        for(int i=0; i<3; i++)
        {
            int nx=Move(i, x);
            if(nx<0 || nx>=MMAX) continue;
            if(vis[nx]!=-1 && vis[nx]!=vis[x]+1) continue;
            pos.push(nx);
            if(vis[K]!=-1 && vis[K]<vis[x])
                return;
            if(vis[nx]==-1)
            vis[nx]=vis[x]+1;
        }
    }
}
int main()
{
    FAST;
    fill(vis, vis+MMAX, -1);
    cin>>N>>K;
    BFS();
    cout<<vis[K]<<'\n';
    cout<<cnt<<'\n';
}
