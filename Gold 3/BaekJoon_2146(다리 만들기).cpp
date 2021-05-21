#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 101
int arr[MMAX][MMAX];
bool vis[MMAX][MMAX];
int dis[MMAX][MMAX];
int N;
int dis_x[]={0,-1,0,1};
int dis_y[]={-1,0,1,0};
queue<pair<int, int>> bridge;
void Find_Side_BFS(int x, int y) // 섬 외각부분 체크
{
    queue<pair<int, int>>pos;
    pos.push({x,y});
    vis[x][y]=true;
    dis[x][y]=-1;
    while(!pos.empty())
    {
        auto p=pos.front();
        pos.pop();
        for(int i=0; i<4; i++)
        {
            int nx=p.first+dis_x[i];
            int ny=p.second+dis_y[i];
            if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
            if(vis[nx][ny]) continue;
            if(arr[nx][ny]==1)
            {
                pos.push({nx,ny});
                dis[nx][ny]=-1;
            }
            else
            {
                bridge.push({nx,ny});
                dis[nx][ny]=1;
            }
            vis[nx][ny]=true;
        }
    }
}

int BFS() // 섬 외곽을 기준으로 다음 섬기준까지 최소거리
{
    int result=INT_MAX;
    while(!bridge.empty())
    {
        auto p=bridge.front();
        bridge.pop();
        for(int i=0; i<4; i++)
        {
            int nx=p.first+dis_x[i];
            int ny=p.second+dis_y[i];
            if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
            if(dis[nx][ny]!=0) continue;

            if(arr[nx][ny]==1 && result>dis[p.first][p.second])
                result=dis[p.first][p.second];
            else if(arr[nx][ny]==0)
            {
                bridge.push({nx,ny});
                dis[nx][ny]=dis[p.first][p.second]+1;
            }
        }
    }
        return result;
}
int main()
{
    FAST;
    cin>>N;
    int min=INT_MAX;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        cin>>arr[i][j];
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(arr[i][j]==1 && !vis[i][j]) // 각 각의 섬 기준마다 최소거리 구해서 비교
            {
                memset(dis, 0, sizeof(dis));
                Find_Side_BFS(i,j);
                int res=BFS();
                if(res<min)
                    min=res;
            }
        }
    }
    cout<<min<<'\n';
}
