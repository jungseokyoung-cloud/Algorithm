#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
struct CCTV{
    int num,x,y,dir;
};
int N,M,ans=INT_MAX;
int arr[9][9];
vector<CCTV> cctv;
int dis_x[]={-1,0,1,0}; // 0은 위 1은 오른쪽 / 2는 아래 3은 왼쪽
int dis_y[]={0,1,0,-1};
void Move_direction(bool up, bool right, bool down, bool left, int x, int y)
{
    if(up){
        for(int i=x-1; i>-1; i--){
            if(arr[i][y]==6) break;
            if(arr[i][y]==0)
                arr[i][y]=-1;
        }
    }
    if(down){
        for(int i=x+1; i<N; i++){
            if(arr[i][y]==6) break;
            if(arr[i][y]==0)
                arr[i][y]=-1;
        }
    }
    if(right){
        for(int j=y+1; j<M; j++){
            if(arr[x][j]==6) break;
            if(arr[x][j]==0)
            arr[x][j]=-1;
        }
    }
    if(left){
        for(int j=y-1; j>-1; j--){
            if(arr[x][j]==6) break;
            if(arr[x][j]==0)
            arr[x][j]=-1;
        }
    }
}
void Check_Min(int idx)
{
    int cx=cctv[idx].x;
    int cy=cctv[idx].y;
    int type=cctv[idx].num;
    int direction=cctv[idx].dir;
    
    if(type==1){
        if(direction==0)
            Move_direction(true, false, false, false, cx, cy);
        else if(direction==1)
            Move_direction(false, true, false, false, cx, cy);
        else if(direction==2)
            Move_direction(false, false, true, false, cx, cy);
        else if(direction==3)
            Move_direction(false, false, false , true, cx, cy);
    }
    else if(type==2){
        if(direction==0 || direction==2)
            Move_direction(true, false, true, false, cx, cy);
        else
            Move_direction(false, true, false , true, cx, cy);
    }
    else if(type==3){
        if(direction==0)
            Move_direction(true, true, false, false, cx, cy);
        else if(direction==1)
            Move_direction(false, true, true, false, cx, cy);
        else if(direction==2)
            Move_direction(false, false, true, true, cx, cy);
        else if(direction==3)
            Move_direction(true, false, false, true, cx, cy);
    }
    else if(type==4){
        if(direction==0)
            Move_direction(true, true, false, true, cx, cy);
        else if(direction==1)
            Move_direction(true, true, true, false, cx, cy); //1
        else if(direction==2)
            Move_direction(false, true, true, true, cx, cy);
        else if(direction==3)
            Move_direction(true, false, true, true, cx, cy); // 3
    }
    else if(type==5){
        Move_direction(true, true, true, true, cx, cy);
    }
}
int Check_Area(){
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
void Move_CCTV(int idx)
{
    if(idx==cctv.size())
    {
        int backup[9][9];
        memcpy(backup, arr, sizeof(arr));
        for(int i=0; i<cctv.size(); i++)
            Check_Min(i);
        int com=Check_Area();
        ans=min(com, ans);
        memcpy(arr, backup, sizeof(arr));
        return;
    }
    for(int i=0; i<4; i++)
    {
        cctv[idx].dir=i;
        Move_CCTV(idx+1);
    }
}
int main()
{
    FAST;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
            if(arr[i][j]!=6 && arr[i][j]!=0)
                cctv.push_back({arr[i][j],i,j,0});
        }
    }
    Move_CCTV(0);
    cout<<ans<<'\n';
}
