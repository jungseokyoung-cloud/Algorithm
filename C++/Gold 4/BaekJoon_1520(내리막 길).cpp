#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
int dis_x[]={1,0,-1,0};
int dis_y[]={0,1,0,-1};
int N,M;
ll arr[501][501];
ll ans[501][501]; //-1이면 탐색 X
ll DFS (int x, int y)
{
    if(x==N-1 && y==M-1)return 1; //끝점에 도달하면!
    if(ans[x][y]>-1)return ans[x][y]; // memoization
    ans[x][y]=0; // 탐색의 시작을 의미함.
    for(int i=0; i<4; i++)
    {
        int nx=x+dis_x[i];
        int ny=y+dis_y[i];
        if(nx<0 || nx>=N || ny<0 || ny>=M)continue;
        if(arr[x][y]<=arr[nx][ny]) continue;
        ans[x][y]+=DFS(nx, ny); // 4방향의 합과 같다.
    }
    return ans[x][y];
}
int main()
{
    memset(ans, -1, sizeof(ans));
    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        cin>>arr[i][j];
    }
    cout<<DFS(0,0)<<'\n';
}
