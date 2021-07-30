#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int INF = INT_MAX;
char board[1000][1000];
int dis[1000][1000];
int T,N,M;
int dis_x[] = {-1,0,1,0};
int dis_y[] = {0,-1,0,1};
queue<pair<int, int>> pos;
int Result(){
    int res  = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            res += dis[i][j];
        }
    }
    return res;
}

void Solve(){
    while(!pos.empty()){
        int x = pos.front().first;
        int y = pos.front().second;
        pos.pop();
        for(int i = 0; i<4; i++){
            int nx = x + dis_x[i];
            int ny = y + dis_y[i];
            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
            if(dis[nx][ny] > dis[x][y] + 1){
                dis[nx][ny] = dis[x][y] + 1;
                pos.push({nx, ny});
            }
        }
    }
}

int main(){
    FAST;
    cin>>T;
    for(int t = 1; t<=T; t++){
        cin>>N>>M;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin>>board[i][j];
                dis[i][j] = INF;
                if(board[i][j] == 'W'){
                    dis[i][j] = 0;
                    pos.push({i,j});
                }
            }
        }
        Solve();

        cout<<"#"<<t<<' '<<Result()<<'\n';
    }
}
