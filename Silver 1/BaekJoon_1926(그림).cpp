#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
bool vis[501][501];
int main()
{
    int dis_x[4]={1,0,-1,0};
    int dis_y[4]={0,1,0,-1};
    FAST;
    int n,m,max=0,compare=0,cnt=0;
    cin>>n>>m;
    int arr[n][m];
    queue<pair<int, int>> pos;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        cin>>arr[i][j];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(!vis[i][j] && arr[i][j]==1) //false는 아직 방문 X true면 방문
            {
                cnt++;
                pos.push({i,j});
                vis[i][j]=true;
                compare=1;
                while(!pos.empty())
                {
                    int x=pos.front().first;
                    int y=pos.front().second;
                    pos.pop();
                    for(int k=0; k<4; k++)
                    {
                        int nx=x+dis_x[k];
                        int ny=y+dis_y[k];
                        if(nx>=0 && nx<n && ny<m && ny>=0 && arr[nx][ny]==1 && !vis[nx][ny])
                        {
                            pos.push({nx,ny});
                            vis[nx][ny]=true;
                            compare++;
                        }
                    }
                }
            }
            if(compare>max)
                max=compare;
        }
    }
    cout<<cnt<<'\n';
    cout<<max<<'\n';
}
