#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
struct Shark{
    int x, y, s, dir, z;
};

int R,C,M, fisherManInfo,ans;
int board[101][101];
bool isCatched[10001];
Shark sharkInfo[10001];
int dis_x[] = {0, -1, 1, 0, 0};
int dis_y[] = {0, 0, 0, 1, -1};

void Input(){
    cin>>R>>C>>M;
    for(int i = 1; i<=M; i++){
        int x, y, s, d ,z;
        cin>>x>>y>>s>>d>>z;
        sharkInfo[i] = {x,y,s,d,z};
        board[x][y] = i;
    }
}

void Move(int &x, int &y, int &dis){
    if(dis == 1 || dis == 3) dis++;
    else dis--;
    
    if(x < 1) x = 1 + abs(1 - x)*dis_x[dis];
    else if(x > R) x = R + abs(R-x)*dis_x[dis];
    else if(y < 1) y = 1 + abs(1 - y)*dis_y[dis];
    else y = C + abs(C - y)*dis_y[dis];
}

void CatchFish(){
    
    for(int i = 1; i<=R; i++){
        if(board[i][fisherManInfo] == 0) continue;
        int idx = board[i][fisherManInfo];
        ans += sharkInfo[idx].z;
        isCatched[idx] = true;
        return;
    }
}

void FishMove(){
    memset(board, 0, sizeof(board));

    for(int i = 1; i<=M; i++){
        if(isCatched[i]) continue;
        int x = sharkInfo[i].x;
        int y = sharkInfo[i].y;
        int cnt = sharkInfo[i].s;
        int dir = sharkInfo[i].dir;

        x = x + cnt*dis_x[dir];
        y = y + cnt*dis_y[dir];

        while(x < 1 || x > R || y < 1 || y > C){
            Move(x, y, dir);
        }
        sharkInfo[i].x = x;
        sharkInfo[i].y = y;
        sharkInfo[i].dir = dir;
        if(board[x][y] == 0){
            board[x][y] = i;
            continue;
        }
        if(sharkInfo[board[x][y]].z > sharkInfo[i].z)  isCatched[i] = true;
        
        else{
            isCatched[board[x][y]] = true;
            board[x][y] = i;
        }
    }
}

void Solve(){
    while(fisherManInfo < C){
        fisherManInfo++;
        CatchFish();
        FishMove();
    }
}

int main(){
    FAST;
    Input();
    Solve();
    cout<<ans<<endl;
}
