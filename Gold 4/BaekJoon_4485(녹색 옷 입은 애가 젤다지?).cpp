#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int board[126][126];
bool vis[126][126];
int ans[126][126];
int dis_x[] = {-1,0,1,0};
int dis_y[] = {0,-1,0,1};
int N;

void Solve(){
    priority_queue<tuple<int, int, int>> pos;
    pos.push({-board[0][0], 0, 0});
    while(!pos.empty()){
        int cost = -get<0>(pos.top());
        int x = get<1>(pos.top());
        int y = get<2>(pos.top());
        pos.pop();
        
        for(int i = 0; i<4; i++){
            int nx = x + dis_x[i];
            int ny = y + dis_y[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            int add = board[nx][ny];
            
            if(ans[nx][ny] > add + cost){
                ans[nx][ny] = add + cost;
                pos.push({-ans[nx][ny], nx, ny});
            }
            
            
        }
    }
}

int main(){
    FAST;
    int T = 1;
    while(1){
        cin>>N;
        if(N == 0) return 0;
        memset(vis, false, sizeof(vis));
        for(int i = 0; i<N; i++){
            fill(ans[i], ans[i]+N, INT_MAX);
        }
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++)
                cin>>board[i][j];
        }
        Solve();
        cout<<"Problem "<<T++<<": "<<ans[N-1][N-1]<<'\n';

    }
}
