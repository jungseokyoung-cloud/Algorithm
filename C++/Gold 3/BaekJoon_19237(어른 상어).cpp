#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N,M,K,shark_cnt,ans;
int shark_command[401][5][5]; //--> i번째 상어의 방향이 j 일때의 k번째 우선순위
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1}; //1번은 위로 2번은 아래 3은 왼쪽 4는 오른쪽
pair<int, int> shark_pos[401]; // 상어의 위치정보 저장
int shark_dir[401]; // 상어의 방향 정보 !
pair<int, int> board[20][20]; // 몇번째 상어의 냄새가 몇인지의 정보저장

void Input(){
    cin>>N>>M>>K;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>board[i][j].first;
            if(board[i][j].first != 0){
                shark_pos[board[i][j].first] = {i,j};
                board[i][j].second = K;
            }
        }
        shark_cnt = M;
    }
    
    for(int i = 1; i<=M; i++)   cin>>shark_dir[i];
    
    for(int k = 1; k<=M; k++){
        for(int i = 1; i<=4; i++){
            for(int j = 1; j<=4; j++){
                cin>>shark_command[k][i][j];
            }
        }
    }
}

void FindNextPoint(){
    for(int i = 1; i<=M; i++){
        int x = shark_pos[i].first;
        int y = shark_pos[i].second;
        int dir = shark_dir[i];
        if(x == -1 && y == -1) continue;
        int nextx = -1,nexty = -1,nextdir;
        
        for(int k = 1; k<=4; k++){
            int idx = shark_command[i][dir][k];
            int nx = x + dx[idx];
            int ny = y + dy[idx];
           
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(board[nx][ny].first == 0){
                nextx = nx;
                nexty = ny;
                nextdir = idx;
                break;
            }
            else if(board[nx][ny].first == i && nextx == -1){
                nextx = nx;
                nexty = ny;
                nextdir = idx;
            }
        }
        shark_pos[i] = {nextx,nexty};
        shark_dir[i] = nextdir;
    }
}

void SetBoard(){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(board[i][j].second == 0) continue;
            board[i][j].second--;
            if(board[i][j].second == 0) board[i][j].first = 0;
        }
    }
    for(int i = 1; i<=M; i++){
        int x = shark_pos[i].first;
        int y = shark_pos[i].second;
        if(x == -1 && y == -1) continue;
        
        if(board[x][y].first != 0 && board[x][y].first != i && board[x][y].second == K){ // 불가능한 조건 !
            shark_pos[i] = {-1,-1};
            shark_cnt--;
            continue;
        }
        board[x][y].first = i;
        board[x][y].second = K;
        
    }
}

void Solve(){
    while(1){
        ans ++;
        FindNextPoint();
        SetBoard();

        if(shark_cnt == 1) return;
        else if (ans >= 1000){
            ans = -1;
            return;
        }
    }
}


int main(){
    FAST;
    Input();
    Solve();
    cout<<ans<<endl;
}
