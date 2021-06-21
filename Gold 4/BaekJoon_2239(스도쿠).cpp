#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
char sudoku[9][9];
bool row[9][10];
bool column[9][10];
bool square[9][10];
bool ans;
vector<pair<int, int>>zero;
void Print(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<<sudoku[i][j];
        }
        cout<<'\n';
    }
}
void Make_vis(int x, int y, bool res, int j){
    row[x][j] = res;
    column[y][j] = res;
    square[(x/3)*3 + y/3][j] = res;
    sudoku[x][y] = j + '0';
}

void Solve(int idx){
    if(ans) return;
    if(idx == zero.size()){
        Print();
        ans = true;
        return;
    }
    
    int x = zero[idx].first;
    int y = zero[idx].second;
    for(int j=1; j<10; j++){
        if(row[x][j] || column[y][j] || square[(x/3)*3 + y/3][j]) continue;
        Make_vis(x, y, true, j);
        Solve(idx+1);
        Make_vis(x, y, false, j);
    }
}

int main(){
    FAST;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin>>sudoku[i][j];
            int num = sudoku[i][j] -'0';
            if(num == 0) zero.push_back({i,j});
            else{
                row[i][num] = true;
                column[j][num] = true;
                square[(i/3)*3 + j/3][num] = true;
            }
        }
    }
    Solve(0);
}
