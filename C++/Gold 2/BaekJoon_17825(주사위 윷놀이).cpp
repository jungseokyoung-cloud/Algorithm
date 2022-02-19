#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

struct boardInfo{
    int now = 0;
    bool blue = false, center = false;
};

int dice[11];
int ans;
boardInfo nowInfo[4];

void input() {
    for(int i = 0; i<10; i++) cin>>dice[i];
}

int moveInfo(int now, bool &blue, int moveCnt, bool &center){
    while(moveCnt--){
        if(now == 40) return 0; // 도착
        
        if(blue){ // 파란색 구역
            if(center) now +=5;
            else if(now == 19 || now == 24 || now == 26){
                now = 25;
                center = true;
            }
            else if(now < 19) now+=3; // 10~19까지 구간
            else if(now < 25) now+=2;
            else if(now == 30) now-=2;
            else if(now > 25) now-=1;
        }
        else now += 2;
    }
    
    if(!blue && now % 10 == 0) blue = true;
    
    return now;
}

bool checkSame(boardInfo &a){
    for(int i = 0; i<4; i++){
            if(a.now == nowInfo[i].now && a.center == nowInfo[i].center && a.blue == nowInfo[i].blue) return true;
            else if(a.now == nowInfo[i].now && a.now == 40)  return true;
    }
    return false;
}

void DFS(int idx, int score){
    if(idx == 10){
        ans = max(ans, score);
        return;
    }

    for(int i = 0; i<4; i++){
        boardInfo before = nowInfo[i];
        boardInfo next = nowInfo[i];
        
        next.now = moveInfo(nowInfo[i].now, next.blue, dice[idx], next.center);

        if(next.now == 0) next = {0, false, false};
        if(next.now != 0 && checkSame(next)) continue;
        nowInfo[i] = next;
        DFS(idx+1, score + nowInfo[i].now);
        nowInfo[i] = before;
    }
}



int main(){
    FAST;
  
    input();
            DFS(0, 0);
    cout<<ans<<endl;
}
