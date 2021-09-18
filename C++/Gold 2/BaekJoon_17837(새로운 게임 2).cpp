#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
struct horseInfo{
    int x, y, dir;
};
int N,K,cnt;
int board[13][13]; // 0 은 흰색 1은 빨강 2는 파랑
vector<int> boardForHourse[13][13];
horseInfo horse[10];
int dis_x[] = {0,0,0,-1,1};
int dis_y[] = {0,1,-1,0,0};

void Input(){
    cin>>N>>K;
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++) cin>>board[i][j];
    }
    for(int i = 0; i<K; i++){
        cin>>horse[i].x>>horse[i].y>>horse[i].dir;
        boardForHourse[horse[i].x][horse[i].y].push_back(i);
    }
}

bool cantGo (int nx, int ny){
    return (nx < 1 || nx > N || ny < 1 || ny > N) || board[nx][ny] == 2;
}

int NextDir(int dir){
    if(dir == 1 || dir == 3) return dir+=1;
    else return dir-=1;
}

void UpdateTable(int x, int y, int nx, int ny, int tar){
    bool find = false;
    int idx = 0;
    int ssize = (int)boardForHourse[x][y].size();
    vector<int> forInsert;
    for(int i = 0; i<ssize; i++){
        int horseIdx = boardForHourse[x][y][i];

        if(horseIdx == tar){
            find = true;
            idx = i;
        }

        if(find){
            forInsert.push_back(horseIdx);
            horse[horseIdx].x = nx;
            horse[horseIdx].y = ny;
        }
    }
    if(board[nx][ny] == 1) reverse(forInsert.begin() ,forInsert.end());
    for(auto res : forInsert) boardForHourse[nx][ny].push_back(res);
    for(int i = ssize-1; i>=idx; i--) boardForHourse[x][y].pop_back(); // 삭제
}

bool HourseMove(){
    for(int i = 0; i<K; i++){
        int &x = horse[i].x;
        int &y = horse[i].y;
        int &dir = horse[i].dir;
        
        if (cantGo(x + dis_x[dir], y + dis_y[dir]))  dir = NextDir(dir); // 파랑이나 빨강의 경우 방향 전환
        int nx = x + dis_x[dir];
        int ny = y + dis_y[dir];

        if(cantGo(nx, ny)) continue; // 방향을 바꿈에도 갈수 없다면 그대로 있음.

        UpdateTable(x, y, nx, ny, i);

        if(boardForHourse[x][y].size() >= 4) return true;
    }
    
    return false;
}


int Solve(){
    while(1){
        cnt++;
        if(HourseMove()) return cnt;

        if(cnt >= 1000) break;
    }
    return -1;
}

int main(){
    FAST;
    Input();
    cout<<Solve()<<endl;
}
