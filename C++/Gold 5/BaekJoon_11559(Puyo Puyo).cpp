#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int ans;
char board[12][6];
bool vis[12][6];
int dis_x[]={0,1,-1,0};
int dis_y[]={1,0,0,-1};

void Pop_Puyo(vector<pair<int, int>> & puyo){
    for(int i=0; i<puyo.size(); i++){
        int x=puyo[i].first;
        int y=puyo[i].second;
        board[x][y]='.';
    }
}

bool BFS(int x, int y, char pu){
    int cnt=1;
    queue<pair<int, int>> pos;
    pos.push({x,y});
    vector<pair<int, int>>puyo;
    puyo.push_back({x,y});
    vis[x][y]=true;
    while(!pos.empty()){
        auto p=pos.front();
        pos.pop();
        for(int i=0; i<4; i++){
            int nx=p.first+dis_x[i];
            int ny=p.second+dis_y[i];
            if(nx<0 || nx>=12 || ny<0 || ny>=6) continue;
            if(vis[nx][ny] || board[nx][ny]!=pu) continue;
            puyo.push_back({nx,ny});
            vis[nx][ny]=true;
            pos.push({nx,ny});
            cnt++;
        }
    }
    if(cnt>=4)
    {
        Pop_Puyo(puyo);
        return true;
    }
    return false;
}
void Next_Board(){
    char change[12][6];
    memset(change, '.', sizeof(change));
    for(int i=0; i<6; i++){
        int idx=11;
        for(int j=11; j>=0; j--){
            if(board[j][i]=='.') continue;
            change[idx--][i]=board[j][i];
        }
    }
    memcpy(board, change, sizeof(board));
}
void Solve(){
    bool res=false;
    memset(vis, false, sizeof(vis));
    for(int i=0; i<12; i++){
        for(int j=0; j<6; j++){
            if(vis[i][j] || board[i][j]=='.') continue;
            if(!res)
                res=BFS(i, j, board[i][j]);
            else
                BFS(i, j, board[i][j]);
        }
    }
    if(res){
        ans++;
        Next_Board();
        Solve();
    }
    else
        return;
}
int main(){
    FAST;
    for(int i=0; i<12; i++){
        for(int j=0; j<6; j++)
        cin>>board[i][j];
    }
    Solve();
    cout<<ans<<'\n';
}
