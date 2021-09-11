#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int stickerCnt[6];
int board[11][11];
bool isAttach[11][11];
int ans = INT_MAX, squareCnt;

void Input(){
    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            cin>>board[i][j];
            if(board[i][j] == 1) squareCnt ++;
        }
    }
}

bool canAttach(int x, int y, int temp){
    if(x + temp -1 > 10 || y + temp - 1 > 10 || stickerCnt[temp] == 5) return false;

    for(int i = x; i<x+temp; i++){
        for(int j = y; j<y + temp; j++){
            if(board[i][j] == 0 || isAttach[i][j]) return false;
        }
    }
    return true;
}

void CheckAttach(int x, int y, int temp, bool res){
    
    for(int i = x; i<x+temp; i++){
        for(int j = y; j<y + temp; j++){
            isAttach[i][j] = res;
        }
    }
}

void FindNextIdx(int &x, int &y){
    while(1){
        if(y >= 10){
            y = 0;
            x ++;
        }
        if(x == 10) return;
        if(board[x][y] == 1 && !isAttach[x][y]) return;
        y++;
    }
}

void AttachSticker(int x, int y, int cnt){
    FindNextIdx(x, y);
    
    if(x == 10){
        ans = min(ans, cnt);
        return;
    }
    
    for(int temp = 5; temp>0; temp--){
        if(!canAttach(x, y, temp)) continue;
        CheckAttach(x, y, temp, true);
        stickerCnt[temp] ++;
        AttachSticker(x, y, cnt + 1);
        
        CheckAttach(x, y, temp, false);
        stickerCnt[temp] --;
    }
    
}

int main(){
    FAST;
    Input();
    AttachSticker(0, 0, 0);
    if(ans == INT_MAX) cout<<"-1"<<endl;
    else cout<<ans<<endl;
    
}
