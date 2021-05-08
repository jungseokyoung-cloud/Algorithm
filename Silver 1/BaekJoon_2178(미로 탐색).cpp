#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
bool vis[101][101];
int main()
{
    int dis_x[]={1,0,-1,0};
    int dis_y[]={0,1,0,-1};
    int N,M;
    cin>>N>>M;
    int arr[N][M];
    string s;
    for(int i=0; i<N; i++)
    {
        cin>>s;
        for(int j=0; j<M; j++)
        arr[i][j]=s[j]-'0';
    }
    queue<pair<int, int>>pos;
    pos.push({0,0});
    while(!pos.empty())
    {
        int x=pos.front().first;
        int y=pos.front().second;
        pos.pop();
        for(int i=0; i<4; i++)
        {
            int nx=x+dis_x[i];
            int ny=y+dis_y[i];
            if(nx>=0 && nx<N && ny>=0 && ny<M && arr[nx][ny]==1 && !vis[nx][ny])
            {
                vis[nx][ny]=true;
                arr[nx][ny]=arr[x][y]+1;
                pos.push({nx,ny});
            }
        }
    }
    cout<<arr[N-1][M-1]<<'\n';
}
