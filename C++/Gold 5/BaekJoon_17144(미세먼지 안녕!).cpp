#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,M,T;
int arr[51][51][1001];
queue<pair<int, int>> dust;
vector<pair<int, int>>air_cir;
int dis_x[]={-1,0,1,0};
int dis_y[]={0,1,0,-1};
int chage_dir(int idx, int dir){
    if(idx==0) dir++;
    else{
        dir--;
        if(dir==-1)
            dir=3;
    }
    return dir;
}
bool OOB(int idx, int nx, int ny){
    if(idx==0){
        return nx<0 || nx>air_cir[0].first || ny<0 || ny>=M;
    }
    else{
        return nx<air_cir[1].first || nx>=N || ny<0 || ny>=M;
    }
}
void Air_circulation(int idx ,int t)
{
    int x=air_cir[idx].first;
    int y=air_cir[idx].second;
    int dir=0;
    if(idx==1) dir=3;
    while(1)
    {
        int nx=x+dis_x[dir];
        int ny=y+dis_y[dir];
        if(OOB(idx, nx, ny)){
            dir=chage_dir(idx, dir);
            continue;
        }
        if(arr[nx][ny][0]==-1) break;
        if(arr[x][y][0]!=-1)
        {
            arr[x][y][t]=arr[nx][ny][t];
            arr[nx][ny][t]=0;
        }
        x=nx;
        y=ny;
    }
}
void Push_queue(int t){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j][t]>0)
                dust.push({i,j});
        }
    }
}
void Dust_Prolifer(int t)
{
    Push_queue(t);
    while(!dust.empty())
    {
        auto pos=dust.front();
        dust.pop();
        int proli=arr[pos.first][pos.second][t]/5;
        int cnt=0;
        for(int i=0; i<4; i++)
        {
            int nx=pos.first+dis_x[i];
            int ny=pos.second+dis_y[i];
            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
            if(arr[nx][ny][0]==-1) continue;
            arr[nx][ny][t+1]+=proli;
            cnt++;
        }
        arr[pos.first][pos.second][t+1]+=(arr[pos.first][pos.second][t]-proli*cnt);
    }
}

int main()
{
    FAST;
    cin>>N>>M>>T;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin>>arr[i][j][0];
            if(arr[i][j][0]==-1)
                air_cir.push_back({i,j});

        }
    }
    for(int i=0; i<T; i++)
    {
        Dust_Prolifer(i);
        Air_circulation(0,i+1);
        Air_circulation(1,i+1);
    }
    int ans=0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
            ans+=arr[i][j][T];
    }
    cout<<ans<<'\n';
}
