#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N,M, change_cnt;
int before_board[31][31];
int after_board[31][31];
int dis_x[] = {-1,0,1,0};
int dis_y[] = {0,-1,0,1};
bool vis[31][31];
bool ans = true;

bool BFS(int i, int j){
    queue<pair<int, int>> pos;
    pos.push({i,j});
    vis[i][j] = true;
    
    while(!pos.empty()){
        int x = pos.front().first;
        int y = pos.front().second;
        pos.pop();
        
        for(int i = 0; i<4; i++){
            int nx = x + dis_x[i];
            int ny = y + dis_y[i];
            
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(vis[nx][ny] || before_board[nx][ny] != before_board[x][y]) continue;
            if(after_board[nx][ny] != after_board[x][y]) return false;
            
            pos.push({nx,ny});
            vis[nx][ny] = true;
        }
    }
    return true;
}

void Solve(){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(vis[i][j]) continue;
            if(after_board[i][j] != before_board[i][j]) change_cnt++;
            if(change_cnt > 1){
                ans = false;
                return;
            }
            ans = BFS(i, j);
            if(!ans) return;
        }
    }
}

int main(){
    FAST;
    cin>>N>>M;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin>>before_board[i][j];
        }
    }
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin>>after_board[i][j];
        }
    }
    Solve();
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
