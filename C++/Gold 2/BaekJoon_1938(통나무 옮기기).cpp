#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
char board[50][50];
int N;
int dis_x[] = {-1,0,1,0};
int dis_y[] = {0,-1,0,1};
string st, en;
set<string> vis;

void Input(){
    cin>>N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            char a;
            cin>>a;
            st.push_back(a);
            
            if(a == 'B') en.push_back('0');
            else if(a == 'E') en.push_back('B');
            else en.push_back(a);
        }
    }
}

bool checkBoundary(int x, int y, string &now, bool vertical){
    int idx1, idx2;
    if(vertical){ // 세로축 평행
        if(y-1 < 0 || y+1 >= N) return true;
        idx1 = x*N + y-1;
        idx2 = x*N + y+1;
    }
    else { // 가로축 평행
        if(x-1 < 0 || x+1 >= N) return true;
        idx1 = (x+1)*N + y;
        idx2 = (x-1)*N + y;
    }
    
    return now[idx1] == '1' || now[idx2] == '1';
}

bool outOfBound(int x, int y, string &now){
    int idx = x*N + y;
    return x < 0 || x >= N || y < 0 || y >=N || now[idx] == '1';
}

void getIndex(pair<int, int> &a, int &idx, string &now){
    for(int i = idx; i<now.size(); i++){
        if(now[i] == 'B'){
            a.first = i/N;
            a.second = i%N;
            idx = i + 1;
            return;
        }
    }
}

void changeBoard(string &temp, int x, int y, int nx, int ny){
    temp[x*N + y] = '0';
    temp[nx*N + ny] = 'B';
}

int BFS(){
    queue<pair<string, int>> pos;
    pos.push({st, 0});
    vis.insert(st);
    while(!pos.empty()){
        string now = pos.front().first;
        int cnt = pos.front().second;
        int idx = 0;
        pos.pop();
        if(now == en) return cnt;
        
        pair<int, int> pos1;
        pair<int, int> pos2;
        pair<int, int> pos3;
        
        getIndex(pos1 , idx, now);
        getIndex(pos2 , idx, now);
        getIndex(pos3 , idx, now);

        for(int i = 0; i<4; i++){ // 상하좌우 움직임
            int nx1 = pos1.first + dis_x[i];
            int ny1 = pos1.second + dis_y[i];
            
            int nx2 = pos2.first + dis_x[i];
            int ny2 = pos2.second + dis_y[i];
            
            int nx3 = pos3.first + dis_x[i];
            int ny3 = pos3.second + dis_y[i];
            string temp = now;
            
            if(outOfBound(nx1, ny1, now) || outOfBound(nx2, ny2, now) || outOfBound(nx3, ny3, now)) continue;
            
            if(i == 0 || i == 1){
                changeBoard(temp, pos1.first, pos1.second, nx1, ny1);
                changeBoard(temp, pos2.first, pos2.second, nx2, ny2);
                changeBoard(temp, pos3.first, pos3.second, nx3, ny3);
            }
            else {
                changeBoard(temp, pos3.first, pos3.second, nx3, ny3);
                changeBoard(temp, pos2.first, pos2.second, nx2, ny2);
                changeBoard(temp, pos1.first, pos1.second, nx1, ny1);
            }
            
            if(vis.find(temp) != vis.end()) continue;
            vis.insert(temp);
            pos.push({temp, cnt + 1});
        }
        
        string temp = now;
        
        if(pos1.first == pos2.first){ //통나무가 가로축 평행
            if(checkBoundary(pos1.first, pos1.second, now, false) || checkBoundary(pos2.first, pos2.second, now, false) || checkBoundary(pos3.first, pos3.second, now, false)) continue;

            int nx1 = pos2.first + 1;
            int ny1 = pos2.second;
            
            int nx3 = pos2.first - 1;
            int ny3 = pos2.second;
            
            if(outOfBound(nx1, ny1, now) || outOfBound(nx3, ny3, now)) continue;
            changeBoard(temp, pos1.first, pos1.second, nx1, ny1);
            changeBoard(temp, pos3.first, pos3.second, nx3, ny3);

            if(vis.find(temp) != vis.end()) continue;
            
            vis.insert(temp);
            pos.push({temp, cnt + 1});
        }
        else { // 통나무가 세로축 평행
            if(checkBoundary(pos1.first, pos1.second, now, true) || checkBoundary(pos2.first, pos2.second, now, true) || checkBoundary(pos3.first, pos3.second, now, true)) continue;
            
            int nx1 = pos2.first;
            int ny1 = pos2.second + 1;
            
            int nx3 = pos2.first;
            int ny3 = pos2.second - 1;
            
            if(outOfBound(nx1, ny1, now) || outOfBound(nx3, ny3, now)) continue;
            changeBoard(temp, pos1.first, pos1.second, nx1, ny1);
            changeBoard(temp, pos3.first, pos3.second, nx3, ny3);

            if(vis.find(temp) != vis.end()) continue;
            
            vis.insert(temp);
            pos.push({temp, cnt + 1});
        }
        
        
    }
    
    return 0;
}

int main(){
    FAST;
    Input();
    cout<<BFS()<<endl;
}
