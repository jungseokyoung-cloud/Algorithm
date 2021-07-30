#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int vis[1002][1002];
int main()
{
    int dis_x[]={1,0,-1,0};
    int dis_y[]={0,1,0,-1};
    FAST;
    int N,M,day=0;
    cin>>M>>N;
    int arr[N][M];
    queue<pair<int, int>>pos;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]==0)
                vis[i][j]=-1;
            if(arr[i][j]==1)
                pos.push({i,j});
        }
    }
   while(!pos.empty())
   {
       int x=pos.front().first;
       int y=pos.front().second;
       pos.pop();
       for(int i=0; i<4; i++)
       {
           int nx=x+dis_x[i];
           int ny=y+dis_y[i];
           if(nx>=0 && nx<N && ny>=0 && ny<M && vis[nx][ny]==-1)
           {
               pos.push({nx,ny});
               vis[nx][ny]=vis[x][y]+1;
           }
       }
   }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(vis[i][j]>day)
                day=vis[i][j];
            if(vis[i][j]==-1)
            {
                cout<<"-1"<<'\n';
                return 0;
            }
        }
    }
    cout<<day<<'\n';
}
