#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cin.tie(0)
bool vis[51][51];
int main()
{
    int dis_x[]={1,0,-1,0};
    int dis_y[]={0,-1,0,1};
    FAST;
    int T,M,N,K;
    cin>>T;
    while(T--)
    {
        int cnt=0;
        cin>>M>>N>>K;
        int arr[N][M];
        memset(arr, 0, sizeof(arr));
        memset(vis, false, sizeof(vis));
        int x,y;
        queue<pair<int, int>>pos;

        for(int i=0; i<K; i++)
        {
            cin>>x>>y;
            arr[y][x]=1;
        }
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(!vis[i][j] && arr[i][j]==1) //false라면 방문 X
                {
                    pos.push({i,j});
                    vis[i][j]=true;
                    cnt++;
                    while(!pos.empty())
                    {
                        auto p=pos.front();
                        pos.pop();
                        for(int k=0; k<4; k++)
                        {
                            int nx=p.first+dis_x[k];
                            int ny=p.second+dis_y[k];
                            if(nx<0 || nx>=N || ny<0 || ny>=M)continue;
                            if(arr[nx][ny]==0 || vis[nx][ny])continue;
                            pos.push({nx,ny});
                            vis[nx][ny]=true;
                        }
                    }
                }
            }
        }
        cout<<cnt<<'\n';
    }//test case
}
