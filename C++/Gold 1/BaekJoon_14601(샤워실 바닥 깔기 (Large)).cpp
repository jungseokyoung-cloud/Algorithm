#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int K;
int board[200][200];
int num;

void Input(){
    int x, y;
    cin>>K>>x>>y;
    board[y-1][x-1] = -1;
}

void Print(){
    for(int i = (1<<K)-1; i>=0; i--){
        for(int j = 0; j<(1<<K); j++){
            cout<<board[i][j]<<' ';
        }
        cout<<endl;
    }
}

bool checkBoard(int x, int y, int s){
    for(int i = x; i<x+s; i++){
        for(int j = y; j<y+s; j++){
            if(board[i][j] != 0) return false; // 이미 타일이 있는 경우
        }
    }
    return true;
}

void Solve(int nowSize, int x, int y){
    if(nowSize == 1) return;
    num++;
    
    int nextSize = nowSize/2;
    
    if(checkBoard(x, y, nextSize))  board[x+nextSize-1][y+nextSize-1] = num; // 1사분면
    if(checkBoard(x, y+nextSize, nextSize)) board[x+nextSize-1][y+nextSize] = num; // 2사분면
    if(checkBoard(x+nextSize, y, nextSize)) board[x+nextSize][y+nextSize-1] = num;
    if(checkBoard(x+nextSize, y+nextSize, nextSize))  board[x+nextSize][y+nextSize] = num;
    
    Solve(nextSize, x, y);
    Solve(nextSize, x, y+nextSize);
    Solve(nextSize, x+nextSize, y);
    Solve(nextSize, x+nextSize, y+nextSize);
}

int main(){
    FAST;
    Input();
    Solve((1<<K), 0, 0);
    Print();
}
