#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N,M,ans = INT_MAX;
char board[100][100];
int mirrorCnt[100][100];
pair<int, int> stPos;
int dis_x[] = {-1,0,1,0};
int dis_y[] = {0,-1,0,1};

void Setting(){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++) mirrorCnt[i][j] = INT_MAX;
    }
}

void BFS(int i, int j){
    queue<tuple<int, int, int, int>> pos;
    pos.push({i,j, -1, -1});
    mirrorCnt[i][j] = -1;
    
    
    while(!pos.empty()){
        int x = get<0>(pos.front());
        int y = get<1>(pos.front());
        int dir = get<2>(pos.front());
        int cnt = get<3>(pos.front());

        if(board[x][y] == 'C' && cnt != -1) {
            ans = min(ans, cnt);
        }
        pos.pop();
        for(int i = 0; i<4; i++){
            int nx = x + dis_x[i];
            int ny = y + dis_y[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(board[nx][ny] == '*') continue;
            int temp = cnt;
            if(dir != i) temp++;
            if(mirrorCnt[nx][ny] < temp) continue;
            
            mirrorCnt[nx][ny] = temp;
            pos.push({nx,ny,i,mirrorCnt[nx][ny]});
        }

    }
}

int main(){
    FAST;
    cin>>M>>N;
    Setting();
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin>>board[i][j];
            if(board[i][j] == 'C') stPos = {i,j};
        }
    }
    BFS(stPos.first, stPos.second);
    cout<<ans<<endl;
}
