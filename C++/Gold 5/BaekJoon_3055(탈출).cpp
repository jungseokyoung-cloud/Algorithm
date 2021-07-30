#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,M;
char arr[51][51];
int water_vis[51][51];
int biber_vis[51][51];
queue<pair<int, int>>water,biber;
int dis_x[]={1,0,-1,0};
int dis_y[]={0,-1,0,1};
void Water(){
    while(!water.empty())
    {
        auto w=water.front();
        water.pop();
        for(int i=0; i<4; i++)
        {
            int nx=w.first+dis_x[i];
            int ny=w.second+dis_y[i];
            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
            if(water_vis[nx][ny]>=0 || arr[nx][ny]=='X' || arr[nx][ny]=='D') continue;
            water_vis[nx][ny]=water_vis[w.first][w.second]+1;
            water.push({nx,ny});
        }
    }
}
void Biber(){
    while(!biber.empty())
    {
        auto b=biber.front();
        biber.pop();
        if(arr[b.first][b.second]=='D')
        {
            cout<<biber_vis[b.first][b.second]<<'\n';
            return;
        }
        for(int i=0; i<4; i++)
        {
            int nx=b.first+dis_x[i];
            int ny=b.second+dis_y[i];
            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
            if(biber_vis[nx][ny]>=0 || arr[nx][ny]=='X') continue;
            if(water_vis[nx][ny]>=0 && water_vis[nx][ny] <= biber_vis[b.first][b.second]+1) continue;
            biber_vis[nx][ny]=biber_vis[b.first][b.second]+1;
            biber.push({nx,ny});
        }
    }
    cout<<"KAKTUS"<<'\n';
}
int main()
{
    FAST;
    cin>>N>>M;
    memset(water_vis, -1, sizeof(water_vis));
    memset(biber_vis, -1, sizeof(biber_vis));
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='*')
            {
                water.push({i,j});
                water_vis[i][j]=0;
            }
            else if(arr[i][j]=='S')
            {
                biber.push({i,j});
                biber_vis[i][j]=0;
            }
        }
    }
    Water();
    Biber();
}
