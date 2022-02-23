#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

struct fish{
    int x, y, dir;
};

int ans;
fish fishInfo[17];
int board[4][4];
int dis_x[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dis_y[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
bool fishDead[17];

void copy_state(int (&beforeMap)[4][4], int (&nowMap)[4][4], fish (&before)[17], fish (&now)[17]){
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            nowMap[i][j] = beforeMap[i][j];
        }
    }
    for(int i = 1; i<17; i++) now[i] = before[i];
}

void updateFishInfo(int x, int y, int fishNum){
    fishInfo[fishNum].x = x;
    fishInfo[fishNum].y = y;
}

void updateFish(int x, int y, int nx, int ny, bool what, int fishNum){
    if(what){ // 싱아기 x-> nx 로 가는거임
        fishDead[fishNum] = what;
        updateFishInfo(x, y, fishNum);
        board[x][y] = fishNum;
        board[nx][ny] = -1;
    }
    else { // 상어 원위치 !
        fishDead[fishNum] = what;
        updateFishInfo(nx, ny, fishNum);
        board[x][y] = -1;
        board[nx][ny] = fishNum;
    }
}

void input() {
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            cin>>board[i][j];
            int dir;
            cin>>dir;
            fishInfo[board[i][j]] = {i,j,dir};
        }
    }
}

void moveFish(){
    for(int i = 1; i<17; i++){
        int x = fishInfo[i].x;
        int y = fishInfo[i].y;
        int dir = fishInfo[i].dir;

        if(fishDead[i]) continue; // 죽으면 안가도록 !!
        
        for(int j = 0; j<7; j++){
            int nx = x + dis_x[dir];
            int ny = y + dis_y[dir];
            if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4 || board[nx][ny] == -1){
                dir ++;
                if(dir == 9) dir = 1;
                continue;
                
            }

            int fishiNum = board[nx][ny];
            int fishDir = fishInfo[fishiNum].dir;
            fishInfo[i] = {nx, ny, dir};

            if(!fishDead[fishiNum]) fishInfo[fishiNum] = {x, y, fishDir};
            swap(board[nx][ny], board[x][y]);
            break;
        }
    }
}

void sharkMove(int x, int y, int dir, int tot){
    ans = max(ans, tot);
    int beforeMap[4][4];
    fish beforeFish[17];
    copy_state(board, beforeMap, fishInfo, beforeFish);
    moveFish();
    
    for(int i = 1; i<=3; i++){
        int nx = x + dis_x[dir]*i;
        int ny = y + dis_y[dir]*i;

        if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) break;
        int fishNum = board[nx][ny];
        if(fishDead[fishNum]) continue;

        updateFish(x, y, nx, ny, true, fishNum); // 상어 현재 -> 나중
        sharkMove(nx, ny, fishInfo[fishNum].dir, tot + fishNum);
        updateFish(x, y, nx, ny, false, fishNum);
    }
    copy_state(beforeMap, board, beforeFish, fishInfo);
}

void solve() {
    int fishNum = board[0][0];
    fishDead[fishNum] = true;
    board[0][0] = -1;
    sharkMove(0, 0, fishInfo[fishNum].dir, fishNum);
}

int main(){
    FAST;
  
    input();
    solve();
    cout<<ans<<endl;
}
