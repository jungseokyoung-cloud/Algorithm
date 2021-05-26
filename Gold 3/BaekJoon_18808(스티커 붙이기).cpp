#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,M,K,y,n,m;
int board[41][41];
int sticker[11][11];
void Attach_Sticker(int x, int y)
{
    for(int i=x; i<x+n; i++)
    {
        for(int j=y; j<y+m; j++)
        {
            if(sticker[i-x][j-y]==1)
            board[i][j]=sticker[i-x][j-y];
        }
    }
}
void Rotate_Sticker(int &dir){
    dir++;
    int arr[11][11];
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            arr[i][j]=sticker[n-j-1][i];
        }
    }
    swap(n, m);
    memcpy(sticker, arr, sizeof(sticker));
}
void Check_Boundary(int dir)
{
    bool ans;
    for(int i=0; i<=N-n; i++)
    {
        for(int j=0; j<=M-m; j++)
        {
            ans=true;
            for(int x=i; x<i+n; x++)
            {
                for(int y=j; y<j+m; y++)
                {
                    if(board[x][y]==1 && sticker[x-i][y-j]==1)
                        ans=false;
                }
            }
            if(ans)
            {
                Attach_Sticker(i,j);
                return;
            }
        }
    }
    Rotate_Sticker(dir);
    if(dir==4)
        return;
    return Check_Boundary(dir);
}
int main()
{
    FAST;
    cin>>N>>M>>K;
    for(int i=0; i<K; i++){
        cin>>n>>m;
        for(int x=0; x<n; x++){
            for(int y=0; y<m; y++){
                cin>>sticker[x][y];
            }
        }
        Check_Boundary(0);
    }
    int cnt=0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(board[i][j]==1)
                cnt++;
        }
    }
    cout<<cnt<<'\n';
}
