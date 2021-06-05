#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int dis_x[]={0,-1,0,1};
int dis_y[]={1,0,-1,0};
int N;
bool board[101][101];
void Draw_Dragon(vector<int> &dirInfo, int x, int y){
    board[x][y]=true;
    for(int i=0; i<dirInfo.size(); i++){
        x+=dis_x[dirInfo[i]];
        y+=dis_y[dirInfo[i]];
        board[x][y]=true;
    }
}
void Dragon_Dir(vector<int> &dirInfo,int gener,int x, int y){
    if(gener==0){
        Draw_Dragon(dirInfo, x, y);
        return;
    }
    vector<int> copy;
    for(int i=dirInfo.size()-1; i>=0; i--)
    copy.push_back((dirInfo[i]+1)%4);
    for(int i=0; i<copy.size(); i++)
    dirInfo.push_back(copy[i]);
    Dragon_Dir(dirInfo, gener-1, x, y);
}
int Check_ans(){
    int cnt=0;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(board[i][j] && board[i+1][j] && board[i][j+1] && board[i+1][j+1])
                cnt++;
        }
    }
    return cnt;
}
int main(){
    FAST;
    cin>>N;
    int x,y,d,g;
    for(int i=0; i<N; i++){
        cin>>y>>x>>d>>g;
        vector<int> dir;
        dir.push_back(d);
        Dragon_Dir(dir ,g, x, y);
    }
    cout<<Check_ans()<<'\n';
}
