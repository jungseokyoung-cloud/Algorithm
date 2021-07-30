#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,M,Max;
int arr[501][501];
bool vis[501][501];
int dis_x[]={1,0,-1,0};
int dis_y[]={0,1,0,-1};
void find_Max(int &sum){
    Max=max(Max, sum);
    sum=0;
}
void DFS(int x, int y, int cnt, int sum)
{
    vis[x][y]=true;
    if(cnt==3)
    {
        Max=max(Max, sum);
        return;
    }
    for(int i=0; i<4; i++)
    {
        int nx=x+dis_x[i];
        int ny=y+dis_y[i];
        if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
        if(vis[nx][ny]) continue;
        vis[nx][ny]=true;
        DFS(nx, ny, cnt+1, sum+arr[nx][ny]);
        vis[nx][ny]=false;
    }
    vis[x][y]=false;
}
void Type_1(int x, int y)
{
    int sum=0;
    if(x+1<N && y+2<M)
        sum=arr[x][y]+arr[x][y+1]+arr[x][y+2]+arr[x+1][y+1];
    find_Max(sum);
    if(x>0 && y+2<M)
        sum=arr[x][y]+arr[x][y+1]+arr[x-1][y+1]+arr[x][y+2];
    find_Max(sum);
    if(x+2<N && y>0)
        sum=arr[x][y]+arr[x+1][y]+arr[x+2][y]+arr[x+1][y-1];
    find_Max(sum);
    if(x+2<N && y+1<M)
        sum=arr[x][y]+arr[x+1][y]+arr[x+1][y+1]+arr[x+2][y];
    find_Max(sum);
}
int main()
{
    FAST;
    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        cin>>arr[i][j];
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            DFS(i, j, 0, arr[i][j]);
            Type_1(i, j);
        }
    }
    cout<<Max<<'\n';
}
