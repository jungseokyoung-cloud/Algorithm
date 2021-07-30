#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
bool vis[8][8];
int N,M,cnt,mmax,wall_num;
int dis_x[]={1,0,-1,0};
int dis_y[]={0,-1,0,1};
vector<pair<int, int>>v;
void BFS(vector<vector<int>> arr) // 벽이 3개가 만들어지면 바이러스의 개수 파악
{
    cnt=0;
    queue<pair<int, int>>pos;
    for(int i=0; i<v.size(); i++)
    {
        pos.push({v[i].first,v[i].second});
        vis[v[i].first][v[i].second]=true;
    }
    while(!pos.empty())
    {
        auto p=pos.front();
        pos.pop();
        cnt++;
        for(int i=0; i<4; i++)
        {
            int nx=p.first+dis_x[i];
            int ny=p.second+dis_y[i];
            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
            if(vis[nx][ny] || arr[nx][ny]==1) continue;
            pos.push({nx,ny});
            vis[nx][ny]=true;
        }
    }
    mmax=max(mmax, N*M-cnt-wall_num);
}

void Make_Wall(vector<vector<int>> arr,int x,int y, int cnt) // 벽을 만들어줌
{
    arr[x][y]=1;
    if(cnt==3)
    {
        memset(vis, false, sizeof(vis));
        BFS(arr);
        return;
    }
    for(int i=x; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(arr[i][j]==0)
            {
               Make_Wall(arr, i, j, cnt+1);
            }
        }
    }
}
int main()
{
    FAST;
    vector<vector<int>> arr(8, vector<int>(8));
    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]==2)
                v.push_back({i,j});
            if(arr[i][j]==1)
                wall_num++;
        }
    }
    wall_num+=3;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(arr[i][j]==0)
            {
                Make_Wall(arr, i, j, 1);
            }
        }
    }
    cout<<mmax<<'\n';
}
