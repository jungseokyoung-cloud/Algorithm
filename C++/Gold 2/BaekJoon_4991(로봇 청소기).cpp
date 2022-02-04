#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'


int N,M,ans;
char board[21][21];
int dis_x[] = {-1,0,1,0};
int dis_y[] = {0,-1,0,1};
int vis[21][21];
bool vvis[21];

vector<pair<int, int>> graph[21];

void input() {
    
    for(int i = 0; i<21; i++){
        graph[i].clear();
    }
    memset(vvis, false, sizeof(vvis));
    cin>>M>>N;
    int dustInfo = 1;
    if(N == 0 && M == 0) return;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++) {
            cin>>board[i][j];
            if(board[i][j] == 'o') board[i][j] = '0';
            else if(board[i][j] == '*'){ board[i][j] = dustInfo + '0';
                dustInfo++;
            }
        }
    }
}

void BFS(int i, int j){
    for(int x = 0; x<N; x++){
        fill(vis[x], vis[x] + M, -1);
    }
    int idx = board[i][j] -'0';
    queue<pair<int, int>> pos;
    pos.push({i,j});
    vis[i][j] = 0;
    
    while(!pos.empty()){
        int x = pos.front().first;
        int y = pos.front().second;
        pos.pop();
        
        for(int dis = 0; dis<4; dis++){
            int nx = x + dis_x[dis];
            int ny = y + dis_y[dis];
            
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(board[nx][ny] == 'x' || vis[nx][ny] != -1) continue;
            pos.push({nx,ny});
            vis[nx][ny] = vis[x][y] + 1;
            if(board[nx][ny] >= '0' && board[nx][ny] < ';'){
                int newIdx = board[nx][ny] -'0';
                graph[idx].push_back({newIdx, vis[nx][ny]});
            }
        }
    }
}

void DFS(int now, int cnt, int tot){
    if(vvis[now]) return;
    if(cnt == 0){
        ans = min(ans,tot);
        return;
    }
    vvis[now] = true;
    
    for(int i = 0; i<graph[now].size(); i++){
        int next = graph[now][i].first;
        int cost = graph[now][i].second;
        if(vvis[next]) continue;
        DFS(next, cnt-1, tot + cost);
    }
    vvis[now] = false;
}

void solve(){
    int cnt = 0;
    ans = INT_MAX;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(board[i][j] >= '0' && board[i][j] <= ';'){
                BFS(i, j);
                cnt ++;
            }
        }
    }
    DFS(0, cnt-1, 0);
}

int main(){
    FAST;
    while(1){
        input();
       
        if(N == 0 && M == 0) break;
        solve();
        if(ans == INT_MAX) ans = -1;
        cout<<ans<<endl;
    }
}

