#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 301
int arr[MMAX][MMAX][MMAX];
bool vis[MMAX][MMAX][MMAX];
int N,M;
int dis_x[]={1,0,-1,0};
int dis_y[]={0,1,0,-1};
void BFS(int x, int y,int year)
{
    queue<pair<int, int>>pos;
    pos.push({x,y});
    vis[x][y][year]=true;
    while(!pos.empty())
    {
        auto n=pos.front();
        pos.pop();
        int melt=0;
        for(int i=0; i<4; i++)
        {
            int nx=n.first+dis_x[i];
            int ny=n.second+dis_y[i];
            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
            if(vis[nx][ny][year]) continue;
            
            if(arr[nx][ny][year]==0)
            {
                melt++;
            }
            else if(arr[nx][ny][year]>0)
            {
                pos.push({nx,ny});
                vis[nx][ny][year]=true;
            }
         }
        arr[n.first][n.second][year+1]=arr[n.first][n.second][year]-melt;
        if(arr[n.first][n.second][year+1]<0)
            arr[n.first][n.second][year+1]=0;
     }
}
int main()
{
    FAST;
    cin>>N>>M;
    int year=0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
            cin>>arr[i][j][0];
    }
    while(1)
    {
        int cnt=0;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(arr[i][j][year]>0 && !vis[i][j][year])
                {
                    cnt++;
                    BFS(i, j, year);
                }
            }
        }
        if(cnt==0)
        {
            cout<<"0"<<'\n';
            break;
        }
        else if(cnt>1)
        {
            cout<<year<<'\n';
            break;
        }
        year++;
    }
}
