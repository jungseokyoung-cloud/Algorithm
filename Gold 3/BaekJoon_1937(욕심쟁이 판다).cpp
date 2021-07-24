#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N, ans;
int board[500][500];
int vis[500][500];
int dis_x[] = {0,-1,0,1};
int dis_y[] = {-1,0,1,0};

int DFS(int x, int y){
    if(vis[x][y] != 0) return vis[x][y];
    
    vis[x][y] = 1;
    
    for(int i = 0; i<4; i++){
        int nx = x + dis_x[i];
        int ny = y + dis_y[i];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if(board[x][y] >= board [nx][ny]) continue;
        vis[x][y] = max(vis[x][y], DFS(nx, ny) + 1);
    }
    
    return vis[x][y];
}

void Solve(){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++) ans = max(ans, DFS(i, j));
    }
}

int main(){
    FAST;
    cin>>N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++) cin>>board[i][j];
    }
    Solve();
    cout<<ans<<'\n';
}
