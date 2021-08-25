#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N,M,ans;
int board[21][21];
bool vis[21][21];
int dis_x[] = {1,0,-1,0};
int dis_y[] = {0,-1,0,1};
vector<pair<int, int>> zeroPos;
int BFS(int i, int j){
    queue<pair<int, int>> pos;
    pos.push({i,j});
    vis[i][j] = true;
    bool res = true;
    int cnt = 0;
    
    while(!pos.empty()){
        int x = pos.front().first;
        int y = pos.front().second;
        cnt++;
        pos.pop();
        
        for(int i = 0; i<4; i++){
            int nx = x + dis_x[i];
            int ny = y + dis_y[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(vis[nx][ny]) continue;
            if(board[nx][ny] == 0) res = false;
            if(board[nx][ny] == 2){
                pos.push({nx,ny});
                vis[nx][ny] = true;
            }
        }
    }
    if(res) return cnt;
    else return 0;
}

void FindAns(){
    int temp  = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(vis[i][j] || board[i][j] != 2) continue;
            temp += BFS(i, j);
        }
    }
//    cout<<endl<<temp<<endl;
    ans = max(ans, temp);
}

void Solve(int idx, int cnt){
    if(cnt == 2){
        memset(vis, false, sizeof(vis));
        FindAns();
        return;
    }
    
    bool choice = false;
    for(int i = idx; i<zeroPos.size(); i++){
        int x = zeroPos[i].first;
        int y = zeroPos[i].second;
        for(int dis = 0; dis<4; dis++){
            int nx = x + dis_x[dis];
            int ny = y + dis_y[dis];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if(board[nx][ny] == 2){
                choice = true;
                board[x][y] = 1;
                Solve(i+1, cnt+1);
                board[x][y] = 0;
                break;
            }
        }
    }
    
    if(cnt == 1 || !choice) Solve(idx, cnt+1);
}

int main(){
    FAST;
    cin>>N>>M;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin>>board[i][j];
            if(board[i][j] == 0) zeroPos.push_back({i,j});
        }
    }
    Solve(0,0);
    cout<<ans<<endl;
}
