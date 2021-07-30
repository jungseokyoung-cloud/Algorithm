#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,M;
char board[101][101];
int destroy_wall[101][101];
int dis_x[]={1,0,-1,0};
int dis_y[]={0,-1,0,1};

void BFS(){
    queue<pair<int, int>> pos;
    pos.push({0,0});
    destroy_wall[0][0]=0;
    while(!pos.empty()){
        auto p = pos.front();
        pos.pop();
        for(int i=0; i<4; i++){
            int nx = p.first + dis_x[i];
            int ny = p.second + dis_y[i];
            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
            if(destroy_wall[nx][ny]!=-1 && board[nx][ny]=='0' &&destroy_wall[nx][ny]<=destroy_wall[p.first][p.second]) continue;
            if(destroy_wall[nx][ny]!=-1 && board[nx][ny]=='1' && destroy_wall[nx][ny]<=destroy_wall[p.first][p.second]+1) continue;
            pos.push({nx,ny});
            if(board[nx][ny]=='1')
                destroy_wall[nx][ny]=destroy_wall[p.first][p.second]+1;
            else if(board[nx][ny]=='0')
                destroy_wall[nx][ny]=destroy_wall[p.first][p.second];
        }
    }
}

int main(){
    FAST;
    cin>>M>>N;
    memset(destroy_wall, -1, sizeof(destroy_wall));
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++)
        cin>>board[i][j];
    }

    BFS();
    cout<<destroy_wall[N-1][M-1]<<'\n';
}
