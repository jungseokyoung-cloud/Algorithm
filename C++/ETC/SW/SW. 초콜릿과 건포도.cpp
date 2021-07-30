#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int T, N, M;
int board[51][51];
int ans[51][51][51][51];

int Solve(int startx, int starty, int rsize, int csize){
    if(rsize == 1 &&  csize == 1) return 0;
    
    int & ref = ans[startx][starty][rsize][csize];
    if(ref != -1) return ref;
    
    ref = INT_MAX;
    int x = startx + rsize -1;
    int y = starty + csize -1;
    int sum = board[x][y] - board[startx-1][y] - board[x][starty-1] + board[startx-1][starty-1];
    
    for(int i = 1; i < rsize; i++){
        ref = min(ref ,Solve(startx,starty, i, csize) + Solve(startx+i, starty, rsize-i, csize) + sum);
    }
    
    for(int i = 1; i < csize; i++){
        ref = min(ref, Solve(startx, starty, rsize, i) + Solve(startx, starty+i, rsize, csize-i) + sum);
    }
    
    return ref;
}

int main(){
    cin>>T;
    for(int t = 1; t<=T; t++){
        cin>>N>>M;
        memset(ans, -1, sizeof(ans));
        memset(board, 0, sizeof(board));
        for(int i = 1; i<=N; i++){
            for(int  j = 1; j<=M; j++){
                cin>>board[i][j];
                board[i][j] += (board[i-1][j] + board[i][j-1] - board[i-1][j-1]);
            }
        }
        cout<<"#"<<t<<' '<<Solve(1, 1, N, M)<<'\n';
    }
}
