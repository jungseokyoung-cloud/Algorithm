#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int board[16][16];
int dp[16][16][3];
int N,ans;
bool vis[16][16];
int dis_x[] = {0,1,1};
int dis_y[] = {1,1,0};

bool outOfBound(int x, int y, int dis){
    if(x<0 || x>=N || y<0 || y>=N || board[x][y] == 1 || vis[x][y]) return true;
    if(dis == 1 && (vis[x-1][y] || vis[x][y-1])) return true;
    if(dis == 1 && (board[x-1][y] == 1 && board[x][y-1] == 1)) return true;
    return false;
}

void Check_Area(int x, int y, int dis, bool res){
    if(dis == 1){
        vis[x][y] = vis[x-1][y] = vis[x][y-1] = res;
    }
    else vis[x][y] = res;
}

int DFS(int x, int y, int dis){
    if(x == N-1 && y == N-1)    return dp[N-1][N-1][dis] = 1;
    
    int &ref = dp[x][y][dis];
    
    if(ref != -1){
        return ref;
    }
    
    ref = 0;
    
    for(int i = dis-1; i<=dis + 1; i++){
        if(i<0 || i>=3) continue;
        
        int nx = x + dis_x[i];
        int ny = y + dis_y[i];

        if(outOfBound(nx, ny, i))   continue;
        
        Check_Area(nx, ny, i, true);
        ref += DFS(nx, ny, i);
        Check_Area(nx, ny, i, false);
    }
    return ref;
}

int main(){
    FAST;
    cin>>N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>board[i][j];
            if(board[i][j] == 1) vis[i][j] = true;
        }
    }
    
    memset(dp, -1, sizeof(dp));
    cout<<DFS(0, 1, 0)<<'\n';
}
