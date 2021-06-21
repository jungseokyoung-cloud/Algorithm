#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,M,T;
int board[100][100];
bool vis[100][100];
int dis_x[]={1,0,-1,0};
int dis_y[]={0,-1,0,1};
void Melt(int x, int y, vector<pair<int, int>> &melt_c){
    queue<pair<int, int>>pos;
    pos.push({x,y});
    vis[x][y] = true;
    while(!pos.empty()){
        auto p = pos.front();
        pos.pop();
        int melt=0;
        for(int i=0; i<4; i++){
            int nx = p.first + dis_x[i];
            int ny = p.second + dis_y[i];
            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
            if(board[nx][ny] == 0) continue;
            if(board[nx][ny]==2){
                melt++;
                continue;
            }
            if(vis[nx][ny]) continue;
            vis[nx][ny] = true;
            pos.push({nx,ny});
        }
        if(melt >= 2)    melt_c.push_back({p.first,p.second});//next_board[p.first][p.second] = 0;
    }
}
void CheckOutPlace(){
    queue<pair<int, int>>pos;
    pos.push({0,0});
    board[0][0] = 2;
    vis[0][0] = true;
    while (!pos.empty()) {
        auto p = pos.front();
        pos.pop();
        for(int i=0; i<4; i++){
            int nx = p.first + dis_x[i];
            int ny = p.second + dis_y[i];
            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
            if(board[nx][ny] == 1 || vis[nx][ny]) continue;
            board[nx][ny] = 2;
            vis[nx][ny] = true;
            pos.push({nx,ny});
        }
    }
}

void Solve(){
    memset(vis, false, sizeof(vis));
    CheckOutPlace();
    vector<pair<int, int>>pos;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(board[i][j] == 1 && !vis[i][j]){
                Melt(i, j, pos);
            }
        }
    }
    for(int i=0; i<pos.size(); i++){
        auto x = pos[i];
        board[x.first][x.second] = 0;
    }
    if(pos.size()>0){
        T++;
        Solve();
    }
}

int main(){
    FAST;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>board[i][j];
        }
    }
  
    Solve();
    cout<<T<<'\n';
}
