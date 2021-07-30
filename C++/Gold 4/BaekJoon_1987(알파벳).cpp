#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,M,ans;
char board[20][20];
bool isused[26];
int dis_x[]={1,0,-1,0};
int dis_y[]={0,-1,0,1};
void DFS(int x, int y,int cnt){
    ans=max(ans, cnt);
    for(int i=0; i<4; i++){
        int nx=x+dis_x[i];
        int ny=y+dis_y[i];
        if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
        int idx=board[nx][ny]-'A';
        if(isused[idx]) continue;
        isused[idx]=true;
        DFS(nx, ny, cnt+1);
        isused[idx]=false;
    }
}
void Solve(int x, int y, int cnt){
    int idx= board[x][y]-'A';
    if(isused[idx]){
        ans=max(ans,cnt-1);
        return;
    }
    isused[idx]=true;
    for(int i=0; i<4; i++){
        int nx=x+dis_x[i];
        int ny=y+dis_y[i];
        if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
        Solve(nx, ny, cnt+1);
    }
    isused[idx]=false;
}
int main(){
    FAST;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++)
        cin>>board[i][j];
    }
    isused[board[0][0]-'A']=true;
    DFS(0, 0, 1);
//    Solve(0, 0, 1);
    cout<<ans<<'\n';
}
