#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
struct Baby_Shark{
    int x,y;
    int size=2;
    int eatCnt=0;
};
Baby_Shark shark;
vector<pair<int, int>> fish;
int N,ans;
int board[21][21];
int vis[21][21];
int dis_x[]={1,0,-1,0};
int dis_y[]={0,1,0,-1};

void BFS(int x, int y){
    memset(vis, -1, sizeof(vis));
    bool loop=false;
    queue<pair<int, int>>pos;
    pos.push({x,y});
    vis[x][y]=0;
    int fish_x=30,fish_y=30,res=-1;
    while(!pos.empty()){
        auto p = pos.front();
        pos.pop();
        for(int i=0; i<4; i++){
            int nx=p.first+dis_x[i];
            int ny=p.second+dis_y[i];
            if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
            if(board[nx][ny]>shark.size || vis[nx][ny]>=0) continue;
            pos.push({nx,ny});
            vis[nx][ny]=vis[p.first][p.second]+1;
            if(res!=-1 && res<vis[nx][ny]) break;
            if(board[nx][ny]>0 && board[nx][ny]<7 && board[nx][ny]<shark.size){
                loop=true;
                res=vis[nx][ny];
                if(nx<fish_x){
                    fish_x=nx;
                    fish_y=ny;
                }
                else if(nx==fish_x && ny<fish_y){
                    fish_y=ny;
                }
            }
        }
    }
    if(loop)
    {
        
        board[shark.x][shark.y]=0;
        shark.x=fish_x;
        shark.y=fish_y;
        ans+=res;
        board[shark.x][shark.y]=9;
        if(++shark.eatCnt==shark.size){
            shark.eatCnt=0;
            shark.size++;
        }
        BFS(shark.x, shark.y);
    }
}
int main(){
    FAST;
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>board[i][j];
            if(board[i][j]==9){
                shark.x=i;
                shark.y=j;
            }
        }
    }
    BFS(shark.x, shark.y);
    cout<<ans<<'\n';
}
