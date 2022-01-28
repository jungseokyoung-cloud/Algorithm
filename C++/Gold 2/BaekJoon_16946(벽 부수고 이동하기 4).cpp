#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int N,M;
int arr[1000][1000];
bool vis[1000][1000];
int dis_x[] = {-1,0,1,0};
int dis_y[] = {0,-1,0,1};

void input(){
    cin>>N>>M;
    for(int i = 0; i<N; i++){
        string s;
        cin>>s;
        for(int j = 0; j<M; j++) arr[i][j] = s[j] -'0';    // 1은 벽 0은 갈수 있는곳
    }
}

void BFS(int i, int j){
    queue<pair<int, int>> pos;
    vis[i][j] = true;
    pos.push({i,j});
    set<pair<int, int>> addPos;
    
    int add = 0;
    
    while(!pos.empty()){
        int x = pos.front().first;
        int y = pos.front().second;
        pos.pop();
        add++;
        for(int i = 0; i<4; i++){
            int nx = x + dis_x[i];
            int ny = y + dis_y[i];
            if(nx < 0 || nx >=N || ny < 0 || ny >= M) continue;
            if(vis[nx][ny]) continue;
            if(arr[nx][ny] != 0) {
                addPos.insert({nx,ny});
                continue;
            }
            
            vis[nx][ny] = true;
            pos.push({nx,ny});
        }
    }
    for(auto idx = addPos.begin(); idx != addPos.end(); idx ++){
        int x = (*idx).first;
        int y = (*idx).second;
        arr[x][y] += add;
    }
  
}

void Solve(){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(arr[i][j] != 0 || vis[i][j]) continue;
            BFS(i, j);
        }
    }
}

void Print(){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++) cout<<arr[i][j]%10;
        cout<<endl;
    }
}

int main(){
    FAST;
    input();
    Solve();
    Print();
}
