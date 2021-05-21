#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with(0),cin.tie(0),cout.tie(0)
#define MMAX 1001
char arr[MMAX][MMAX];
int vis[MMAX][MMAX][2]; // first는 이동 값 secound 에는 부쉈는지
int dis_x[]={1,0,-1,0};
int dis_y[]={0,-1,0,1};
int N,M;
int BFS(int x,int y)
{
    vis[x][y][0]=1;
    queue<tuple<int,int,int>>pos;
    pos.push({x,y,0});
    while(!pos.empty())
    {
        int x=get<0>(pos.front());
        int y=get<1>(pos.front());
        int destroy=get<2>(pos.front());
        if(x==N-1 && y==M-1)
            return vis[x][y][destroy];
        pos.pop();
        for(int i=0; i<4; i++)
        {
            int nx=x+dis_x[i];
            int ny=y+dis_y[i];
            if(nx<0 || nx>=N || ny<0 || ny>=M)continue; // 범위
            if(destroy==1 && arr[nx][ny]=='1') continue; //벽이 이미 깨고 벽으로 가는경우
            if((destroy==1 ||arr[nx][ny]=='1') && vis[nx][ny][1]>0 ) continue;
            if(destroy==0 && arr[nx][ny]=='0' && vis[nx][ny][0]>0) continue;
            
            if(destroy==0 && arr[nx][ny]=='0')
            {
                pos.push({nx,ny,0});
                vis[nx][ny][0]=vis[x][y][0]+1;
            }
            else
            {
                pos.push({nx,ny,1});
                if(destroy==0)
                    vis[nx][ny][1]=vis[x][y][0]+1;
                else
                    vis[nx][ny][1]=vis[x][y][1]+1;
            }
        }
    }
    return -1;
}
int main()
{
    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
            cin>>arr[i][j];
    }
    cout<<BFS(0, 0)<<'\n';
}
