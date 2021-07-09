#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
char board[5][5];
bool vis[5][5];
vector<pair<int, int>> pos;
int dis_x[] = {0,1,-1,0};
int dis_y[] = {1,0,0,-1};
int ans;

void Check(){ // 이어저있는지 확인
    bool connect[5][5];
    memset(connect, false, sizeof(connect));
    queue<pair<int, int>> now;
    now.push({pos[0].first,pos[0].second});
    connect[pos[0].first][pos[0].second] = true;
    
    int cnt1 = 0, cnt2 = 0;
    while(!now.empty()){
        int x = now.front().first;
        int y = now.front().second;
        cnt1++;
        if(board[x][y] == 'S') cnt2 ++;
        now.pop();
        for(int i = 0; i<4; i++){
            int nx = x + dis_x[i];
            int ny = y + dis_y[i];
            if(nx <0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if(!vis[nx][ny] || connect[nx][ny]) continue;
            connect[nx][ny] = true;
            now.push({nx,ny});
        }
    }
    if(cnt1 == 7 && cnt2>=4) ans++;
}

void Solve(int idx, int k){
    if(pos.size() == 7){
        Check();
        return;
    }
    
    for(int i = idx; i<5; i++){
        for(int j = 0; j<5; j++){
            if(vis[i][j]) continue;
            if(i == idx && j<k) continue;
            vis[i][j] = true;
            pos.push_back({i,j});
            Solve(i,j+1);
            vis[i][j] = false;
            pos.pop_back();
        }
    }
}

int main(){
    FAST;
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            cin>>board[i][j];
        }
    }
    Solve(0,0);
   
    cout<<ans<<'\n';
}
