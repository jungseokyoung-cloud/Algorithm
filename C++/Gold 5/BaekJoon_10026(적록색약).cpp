#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 101
char arr[MMAX][MMAX];
bool vis[MMAX][MMAX];
bool vis_2[MMAX][MMAX];
int cnt1,cnt2,N;
int dis_x[]={-1,0,1,0};
int dis_y[]={0,-1,0,1};
void BFS(int i, int j)
{
    queue<pair<int, int>>pos;
    pos.push({i,j});
    vis[i][j]=true;
    while(!pos.empty())
    {
        auto x=pos.front();
        pos.pop();
        for(int dis=0; dis<4; dis++)
        {
            int nx=x.first+dis_x[dis];
            int ny=x.second+dis_y[dis];
            if(nx<0 || nx>=N || ny<0 || ny>=N)continue;
            if(vis[nx][ny] || arr[nx][ny]!=arr[i][j])continue;
            pos.push({nx,ny});
            vis[nx][ny]=true;
        }
    }
}
void BFS2(int i, int j)
{
    queue<pair<int, int>>pos;
    pos.push({i,j});
    vis_2[i][j]=true;
    bool ans=false;
    if(arr[i][j]!='B') //G 나 R라면
        ans=true;
    while(!pos.empty())
    {
        auto x=pos.front();
        pos.pop();
        for(int dis=0; dis<4; dis++)
        {
            int nx=x.first+dis_x[dis];
            int ny=x.second+dis_y[dis];
            if(nx<0 || nx>=N || ny<0 || ny>=N)continue;
            if(vis_2[nx][ny])continue;
            if(!ans && arr[nx][ny]!='B')continue; // false라면 blue인경우
            if(ans && arr[nx][ny]=='B') continue;
            pos.push({nx,ny});
            vis_2[nx][ny]=true;
        }
    }
}
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        cin>>arr[i][j];
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(!vis[i][j])
            {
                cnt1++;
                BFS(i, j);
            }
            if(!vis_2[i][j])
            {
                cnt2++;
                BFS2(i,j);
            }
        }
    }
    cout<<cnt1<<' '<<cnt2<<'\n';
}
