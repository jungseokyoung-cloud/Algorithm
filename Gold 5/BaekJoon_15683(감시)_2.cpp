#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,M,ans=INT_MAX;
int arr[10][10];
int arr2[10][10];
int dis_x[]={-1,0,1,0}; // 0은 위 1은 오른쪽 / 2는 아래 3은 왼쪽
int dis_y[]={0,1,0,-1};
vector<pair<int, int>>cctv;
void Check_Arr(int x, int y, int dir)
{
    if(dir>3)
        dir-=4;
    while(1)
    {
        x+=dis_x[dir];
        y+=dis_y[dir];
        if(x<0 || x>=N || y<0 || y>=M) return;
        if(arr[x][y]==6) return;
        if(arr[x][y]==0)
            arr[x][y]=-1;
    }
}
int Check_Safe(){
    int cnt=0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(arr[i][j]==0)
                cnt++;
        }
    }
    return cnt;
}
void Find_CCTVdir()
{
    for(int tmp = 0; tmp < (1<<(2*cctv.size())); tmp++)
    {
        memcpy(arr2, arr, sizeof(arr));
        int ntmp=tmp;
        for(int i=0; i<cctv.size(); i++)
        {
            int dir=ntmp%4;
            int x=cctv[i].first;
            int y=cctv[i].second;
            int type=arr[cctv[i].first][cctv[i].second];
            if(type==1)
                Check_Arr(x, y, dir);
            else if(type==2)
            {
                Check_Arr(x, y, dir);
                Check_Arr(x, y, dir+2);
            }
            else if(type==3)
            {
                Check_Arr(x, y, dir);
                Check_Arr(x, y, dir+1);
            }
            else if(type==4)
            {
                Check_Arr(x, y, dir);
                Check_Arr(x, y, dir+1);
                Check_Arr(x, y, dir+2);
            }
            else{
                Check_Arr(x, y, dir);
                Check_Arr(x, y, dir+1);
                Check_Arr(x, y, dir+2);
                Check_Arr(x, y, dir+3);
            }
            ntmp/=4;
        }
        int com=Check_Safe();
        ans=min(ans, com);
        memcpy(arr, arr2, sizeof(arr));
    }
}
int main()
{
    FAST;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]!=6 && arr[i][j]!=0)
                cctv.push_back({i,j});
        }
    }
    Find_CCTVdir();
    cout<<ans<<'\n';
}
