#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
bool isused[9][10][3];
int sudoku[9][9];
vector<pair<int, int>> zero;
bool ans;
bool check_ans(){
    bool check[10][2];
    for(int i=0; i<9; i++){    // 가로 세로 확인
        memset(check, false, sizeof(check));
        for(int j=0; j<9; j++){
            int now_num=sudoku[i][j];
            if(check[now_num][0]) return false;
            check[now_num][0]=true;
            int now_num2=sudoku[j][i];
            if(check[now_num2][1]) return false;
            check[now_num2][1]=true;
        }
    }
    bool check_2[10];
    int sx=0,sy=0;
    for(int i=0; i<9; i++){      //3X3 정사각형 체크
        memset(check_2, false, sizeof(check_2));
        for(int x=sx; x<3; x++){
            for(int y=sy; y<3; y++){
                int now_num=sudoku[x][y];
                if(check_2[now_num]) return false;
                check_2[now_num]=true;
            }
        }
        if(i%3==2){
            sy=0;
            sx+=3;
        }
        else
            sy+=3;
    }
    
    return true;
}
void Print_sudoku(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++)
            cout<<sudoku[i][j]<<' ';
            cout<<'\n';
    }
}
void Solve(int idx){
    if(ans) return;
    if(!ans && idx==zero.size()){
        ans=check_ans();
        if(ans)
            Print_sudoku();
        return;
    }
    int x=zero[idx].first;
    int y=zero[idx].second;
    int ind=(x/3)*3+y/3;
    for(int i=1; i<10; i++){
        if(isused[x][i][0] || isused[y][i][1] || isused[ind][i][2]) continue;
        sudoku[x][y]=i;
        isused[x][i][0]=true;
        isused[y][i][1]=true;
        isused[ind][i][2]=true;
        Solve(idx+1);
        sudoku[x][y]=0;
        isused[x][i][0]=false;
        isused[y][i][1]=false;
        isused[ind][i][2]=false;
    }
}
int main(){
    FAST;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++)
        {
            cin>>sudoku[i][j];
            if(sudoku[i][j]>0)
            {
                isused[i][sudoku[i][j]][0]=true; // 가로
                isused[j][sudoku[i][j]][1]=true; // 세로
                int idx=(i/3)*3+j/3;
                isused[idx][sudoku[i][j]][2]=true; // 3X3
            }
            else if(sudoku[i][j]==0) zero.push_back({i,j});
        }
    }
    Solve(0);
}
