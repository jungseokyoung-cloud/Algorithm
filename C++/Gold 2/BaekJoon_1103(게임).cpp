#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
const int INF = 10000000;
int N, M, ans;
char board[51][51];
bool vis[51][51];
int dp[51][51];
int dis_x[] = {-1,0,1,0};
int dis_y[] = {0,-1,0,1};

void Input(){
    cin>>N>>M;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin>>board[i][j];
        }
    }
}

int Solve(int x, int y){
    if(vis[x][y]) return INF;
    int &ref = dp[x][y];
    
    if(ref != -1) return ref;
    
    ref = 1;
    vis[x][y] = true;
    for(int i = 0; i<4; i++){
        int cnt = board[x][y] - '0';
        int nx = x + dis_x[i] * cnt;
        int ny = y + dis_y[i] * cnt;
        
        if(nx < 0 || nx >= N || ny < 0 || ny >= M || board[nx][ny] == 'H') continue;
        
        ref = max(ref, Solve(nx, ny) + 1);
        
    }
    vis[x][y] = false;
    return ref;
}

int main(){
    FAST;
    Input();
    int ans = Solve(0, 0);
    if (ans >= INF) cout<<"-1"<<endl;
    else cout<<ans<<endl;
}
