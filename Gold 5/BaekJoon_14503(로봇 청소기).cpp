#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int arr[51][51];
bool vis[51][51];
int N,M,direction,current_x,current_y,cnt; //0은 위/ 오른쪽 1/ 아래 2/ 왼쪽 2
int dis_x[]={-1,0,1,0};
int dis_y[]={0,1,0,-1};
void DFS(int x, int y)
{
    if(!vis[x][y])
    {
        vis[x][y]=true;
        cnt++;
    }
    for(int i=0; i<4; i++)
    {
        direction--;
        if(direction<0) direction+=4;
        int nx=x+dis_x[direction];
        int ny=y+dis_y[direction];
        if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
        if(arr[nx][ny]==1 || vis[nx][ny]) continue;
        return DFS(nx, ny);
    }
    int back=direction+2;
    if(back >3) back%=4;
    int nx=x+dis_x[back];
    int ny=y+dis_y[back];
    if(arr[nx][ny]==0)
    return DFS(nx, ny);
}
int main()
{
    FAST;
    cin>>N>>M;
    cin>>current_x>>current_y>>direction;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        cin>>arr[i][j];
    }
    DFS(current_x, current_y);
    cout<<cnt<<'\n';
}
