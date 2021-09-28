#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int r1,r2,c1,c2;
int board[50][5];
int dis_x[] = {0,-1,0,1};
int dis_y[] = {1,0,-1,0};
int cnt, lineCnt = 1, dir, progressCnt, num = 1, x, y, changeDirCnt;
string maxValue;

void Change_Info(){
    num ++;
    x = x + dis_x[dir];
    y = y + dis_y[dir];
    progressCnt++;
}

void Input_board(){
    int ssize = (r2-r1+1)*(c2-c1+1);
    
    while(cnt < ssize){
        if(r1 <= x && x <= r2 && c1 <= y && y <= c2 ){
            maxValue = to_string(num);
            board[x-r1][y-c1] = num;
            cnt++;
        }
        
        Change_Info();
        
        if(progressCnt < lineCnt) continue;
        changeDirCnt++;
        dir = (dir + 1)%4;
        progressCnt = 0;
        
        if(changeDirCnt < 2) continue;
        changeDirCnt = 0;
        lineCnt++;
    }
}

void Print(){
    int buff = maxValue.size();
    for(int i = 0; i<(r2-r1 + 1); i++){
        for(int j = 0; j<(c2-c1 + 1); j++){
            string now = to_string(board[i][j]);
            
            int spaceSize = buff - (int)now.size();
            
            for(int k = 0; k<spaceSize; k++) cout<<" ";
            cout<<now<<' ';
        }
        cout<<endl;
    }
}

int main(){
    FAST;
    cin>>r1>>c1>>r2>>c2;
    Input_board();
    Print();
}
