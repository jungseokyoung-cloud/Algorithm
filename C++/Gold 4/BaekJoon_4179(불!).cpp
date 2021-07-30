#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int vis[1001][1001];
int fire_vis[1001][1001];
int main()
{
    int dis_x[]={1,0,-1,0};
    int dis_y[]={0,1,0,-1};
    FAST;
    int n,m;
    cin>>n>>m;
    char arr[n][m];
    queue<pair<int, int>>pos;
    queue<pair<int, int>>fire;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='J')
            {
                pos.push({i,j});
                vis[i][j]=1;
            }
           else if(arr[i][j]=='F')
           {
               fire.push({i,j});
               fire_vis[i][j]=1;
           }
        }
    }
    while(!fire.empty())
    {
        auto f=fire.front();
        fire.pop();
        for(int i=0; i<4; i++)
        {
            int fx=f.first+dis_x[i];
            int fy=f.second+dis_y[i];
            if(fx<0 || fx>=n || fy<0 || fy>=m)continue;
            if(arr[fx][fy]=='#' || fire_vis[fx][fy]>0) continue;
                fire_vis[fx][fy]=fire_vis[f.first][f.second]+1;
                fire.push({fx,fy});
        }
    }
   while(!pos.empty())
   {
       auto p=pos.front();
       pos.pop();
       if(p.first==0 || p.first==n-1 || p.second==0 || p.second==m-1)
       {
           cout<<vis[p.first][p.second]<<'\n';
           return 0;
       }
       for(int i=0; i<4; i++)
       {
           int nx=p.first+dis_x[i];
           int ny=p.second+dis_y[i];
           if(nx<0 || nx>=n || ny<0 || ny>=m)continue;
           if(fire_vis[nx][ny]>0 && vis[p.first][p.second]+1>=fire_vis[nx][ny])continue;
           if(vis[nx][ny]>0 || arr[nx][ny]=='#')continue;
               vis[nx][ny]=vis[p.first][p.second]+1;
               pos.push({nx,ny});
       }
   }
        cout<<"IMPOSSIBLE"<<'\n';
}
