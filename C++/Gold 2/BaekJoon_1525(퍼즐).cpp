#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
string st;
set<string> vis;
int ans = -1;
int dis_x[] = {-1,0,1,0};
int dis_y[] = {0,1,0,-1};
void Input(){
    int num;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            cin>>num;
            st.push_back(num + '0');
        }
    }
}
void Print(string s){
    for(int i = 0; i<s.size(); i++){
        if(i%3 == 0) cout<<endl;
        cout<<s[i]<<' ';
    }
    cout<<endl;
}

int GetZeroIdx(string &s){
    for(int i = 0; i<s.size(); i++){
        if(s[i] == '0') return i;
    }
    return 0;
}

void BFS(){
    queue<pair<string, int>> node;
    node.push({st, 0});
    vis.insert(st);
    
    while(!node.empty()){
        string now = node.front().first;
        int cnt = node.front().second;
        node.pop();
        if(now == "123456780"){
            ans = cnt;
            return;
        }
        int idx = GetZeroIdx(now);
        int x = idx/3;
        int y = idx%3;
        
        for(int i = 0; i<4; i++){
            int nx = x + dis_x[i];
            int ny = y + dis_y[i];
            string next = now;

            if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
            swap(next[nx*3 + ny], next[idx]);
            
            if(vis.find(next) != vis.end()) continue;
            vis.insert(next);
            node.push({next, cnt + 1});
        }
    }
}

int main(){
    FAST;
    Input();
    BFS();
    cout<<ans<<endl;
}
