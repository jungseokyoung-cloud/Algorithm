#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
string ans, temp;
int dis_x[] = {-1,0,1,0};
int dis_y[] = {0,-1,0,1};
set<string> vis;
int res = -1;

void Input(){
    int num;
    ans = "123456780";
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            cin>>num;
            temp += (num + '0');
        }
    }
}

void Solve(){
    vis.insert(temp);
    queue<pair<string, int>> node;
    node.push({temp,0});
    
    while(!node.empty()){
        string now = node.front().first;
        int cnt = node.front().second;
        if(now == ans){
            res = cnt;
            return;
        }
        
        node.pop();
        
        int idx = (int)now.find('0');
        int x = idx/3;
        int y = idx%3;
        
        for(int i = 0; i<4; i++){
            int nx = x + dis_x[i];
            int ny = y + dis_y[i];
            if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
            
            string next = now;
            swap(next[idx], next[nx*3 + ny]);
            if(vis.find(next) != vis.end()) continue;
            
            vis.insert(next);
            node.push({next, cnt + 1});
        }
    }
}

int main(){
    FAST;
    Input();
    Solve();
    cout<<res<<endl;
}
