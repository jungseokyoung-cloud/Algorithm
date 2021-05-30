#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,M,K,up=1,Left=3,front=5,current_x,current_y;
int arr[21][21];
int dice_pos[7]; // 1과 6은 마주봄. (3/4) / (5/2)
int dis_x[]={0,0,-1,1};
int dis_y[]={1,-1,0,0};
void Throw_Dice(int dir){   // 처음 front 값은 5
    if(dir==1)
    {
        int down=7-up;
        up=Left;
        Left=down;
    }
    else if(dir==2)
    {
        int right=7-Left;
        Left=up;
        up=right;
    }
    else if(dir==3)
    {
        int down=7-up;
        up=front;
        front=down;
    }
    else if(dir==4)
    {
        int back=7-front;
        front=up;
        up=back;
    }
}
void Move_Dice(int dir)
{
    int nx=current_x+dis_x[dir-1];
    int ny=current_y+dis_y[dir-1];
    if(nx<0 || nx>=N || ny<0 || ny>=M) return;
    Throw_Dice(dir);
    int down=7-up;
    if(arr[nx][ny]==0) //지도가 0인경우 바닥면 복사
        arr[nx][ny]=dice_pos[down];
    else{
        dice_pos[down]=arr[nx][ny];
        arr[nx][ny]=0;
    }
    current_x=nx;
    current_y=ny;
    cout<<dice_pos[up]<<'\n';
}
int main()
{
    FAST;
    int order;
    cin>>N>>M>>current_x>>current_y>>K;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        cin>>arr[i][j];
    }
    for(int i=0; i<K; i++)
    {
        cin>>order;
        Move_Dice(order);
    }
}
