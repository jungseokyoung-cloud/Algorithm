#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,direction,Max; //0은 왼쪽으로 움질일때,  1은 아래쪽   2는 오른쪽. 3은 위
int arr[21][21];
int board[21][21];
void Rotate(){
    direction++;
    int arr2[21][21];
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            arr2[i][j]=arr[N-j-1][i];
        }
    }
    memcpy(arr, arr2, sizeof(arr));
}
void Move_2048(int dir){
    
    while(dir!=direction){
        Rotate();
        direction%=4;
    }
    
    int change[21][21]={ };
    for(int i=0; i<N; i++)
    {
        int idx=0;
        for(int j=0; j<N; j++)
        {
            if(arr[i][j]==0) continue;

            if(change[i][idx]==0)
                change[i][idx]=arr[i][j];
            else if(change[i][idx]==arr[i][j])
                change[i][idx++]*=2;
            else if(change[i][idx]!=arr[i][j])
                change[i][++idx]=arr[i][j];
        }
    }
    memcpy(arr, change, sizeof(arr));
}
void Check_Max(){
    int mmax=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j]>mmax)
                mmax=arr[i][j];
        }
    }
    Max=max(Max, mmax);
}

int main(){
    FAST;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        cin>>board[i][j];
    }
    for(int i=0; i<1024; i++)
    {
        int temp=i;
        direction=0;
        memcpy(arr, board, sizeof(arr));
        for(int j=0; j<5; j++){
            int dir=temp%4;
            Move_2048(dir);
            temp/=4;
        }
        Check_Max();
    }
    cout<<Max<<'\n';
}
