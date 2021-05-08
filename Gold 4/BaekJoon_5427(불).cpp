#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 1001
char arr[MMAX][MMAX];
int vis[MMAX][MMAX];
int fire[MMAX][MMAX];
int dis_x[]={1,0,-1,0};
int dis_y[]={0,-1,0,1};

int main()
{
    FAST;
    int w,h,T;
    cin>>T;
    while(T--)
    {
        bool ans=false;
        memset(fire, 0, sizeof(fire));
        memset(vis, 0, sizeof(vis));
        queue<pair<int, int>>pos;
        queue<pair<int, int>>pos_fire;
        cin>>w>>h;
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                cin>>arr[i][j];
                if(arr[i][j]=='@')
                {
                    pos.push({i,j});
                    vis[i][j]=1;
                }
                else if(arr[i][j]=='*')
                {
                    pos_fire.push({i,j});
                    fire[i][j]=1;
                }
            }
        }
        while (!pos_fire.empty())
        {
            auto fx=pos_fire.front();
            pos_fire.pop();
            for(int i=0; i<4; i++)
            {
                int nx=fx.first+dis_x[i];
                int ny=fx.second+dis_y[i];
                if(nx<0 || nx>=h || ny<0 || ny>=w)continue;
                if(arr[nx][ny]=='#' || fire[nx][ny]>0)continue; //fire 이 0보다 크다면 이미 방문함.
                fire[nx][ny]=fire[fx.first][fx.second]+1;
                pos_fire.push({nx,ny});
            }
        }
        while(!pos.empty())
        {
            auto x=pos.front();
            pos.pop();
            if(x.first==h-1 || x.first==0 || x.second==0 || x.second==w-1)
            {
                cout<<vis[x.first][x.second]<<'\n';
                ans=true;
                break;
            }
            for(int i=0; i<4; i++)
            {
                int nx=x.first+dis_x[i];
                int ny=x.second+dis_y[i];
                if(nx<0 || nx>=h || ny<0 || ny>=w)continue;
                if(arr[nx][ny]=='#' || vis[nx][ny]>0) continue;
                if(fire[nx][ny]>0 && fire[nx][ny]<=vis[x.first][x.second]+1)continue;
                vis[nx][ny]=vis[x.first][x.second]+1;
                pos.push({nx,ny});
            }
        }
        if(!ans)
        {
            cout<<"IMPOSSIBLE"<<'\n';
        }
    }
}
