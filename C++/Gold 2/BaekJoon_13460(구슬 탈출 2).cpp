#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
char board[10][10];
int N,M;
bool ans;
int vis[10][10][10][10];
int dis_x[] = {0,1,0,-1};
int dis_y[] = {1,0,-1,0};


void Solve(int rx1, int ry1, int bx1, int by1){
    queue<pair<int, int>> red;
    queue<pair<int, int>> blue;
    red.push({rx1,ry1});
    blue.push({bx1,by1});
    vis[rx1][ry1][bx1][by1] = 0;
    
    while(!red.empty()){
        int sized = blue.size();
        while(sized--){
            int rx = red.front().first;
            int ry = red.front().second;
            int bx = blue.front().first;
            int by = blue.front().second;
            int value = vis[rx][ry][bx][by];
            
            red.pop();
            blue.pop();
            if(value >= 10)  return;
            
            for(int i = 0; i<4; i++){
                bool res = true;
                
                int before_rx = rx;
                int before_ry = ry;
                int before_bx = bx;
                int before_by = by;
                while(1){
                    bool resblue = false;
                    bool resred = false;
                    bool redhole = false;
                    
                    int nrx = before_rx + dis_x[i];
                    int nry = before_ry + dis_y[i];
                    int nbx = before_bx + dis_x[i];
                    int nby = before_by + dis_y[i];
                    
                    if(board[nrx][nry] == 'O'){ // 빨간공이 구멍에 빠지믄
                        redhole = true;
                        ans = true;
                     }
                    
                    if(board[nbx][nby] == 'O'){ // 파란공이 구멍에 빠지면!!!!!
                        res = false;
                        ans = false;
                        break;
                    }
                   if(board[nrx][nry] == '#' || (nrx == before_bx && nry == before_by)){ // 공이 막고  있거나 벽이라면
                        resred = true;
                        nrx = before_rx;
                        nry = before_ry;
                    }
                
                    if(board[nbx][nby] == '#' || (!redhole && (nbx == before_rx && nby == before_ry))){ // 공이 막고 있거나 벽이라면
                        resblue = true;
                        nbx = before_bx;
                        nby = before_by;
                    }
                    
                    if(resblue && resred) break; // 둘다 멈춘 상태라면
                    
                    before_rx = nrx;//값 갱신
                    before_ry = nry;
                    before_bx = nbx;
                    before_by = nby;

                }
                if(!res || vis[before_rx][before_ry][before_bx][before_by] != -1) continue;
                vis[before_rx][before_ry][before_bx][before_by] = value + 1;
                red.push({before_rx, before_ry});
                blue.push({before_bx, before_by});
                
                if(ans){
                    cout<<vis[before_rx][before_ry][before_bx][before_by]<<endl;
                    return;
                }
            }
        }
        
    }

}

int main(){
    FAST;
    cin>>N>>M;
    memset(vis, -1, sizeof(vis));
    
    int rx,ry,bx,by;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin>>board[i][j];
            if(board[i][j] == 'R'){
                rx = i;
                ry = j;
            }
            else if(board[i][j] == 'B'){
                bx = i;
                by = j;
            }
        }
    }
    Solve(rx, ry, bx, by);
    if(!ans) cout<<"-1"<<'\n';
}
