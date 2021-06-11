#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
vector<int>connect [201];
bool vis[201];
vector<int>travel;
int N,cnt;
bool ans;
bool Travel(int start, int end){
    queue<int> node;
    node.push(start);
    vis[start]=true;
    while(!node.empty()){
        int now=node.front();
        if(now==end) return true;
        node.pop();
        for(int i=0; i<connect[now].size(); i++){
            int next=connect[now][i];
            if(vis[next]) continue;
            vis[next]=true;
            node.push(next);
        }
    }
    return false;
}

void Solve(){
    for(int i=1; i<travel.size(); i++){
        memset(vis, false, sizeof(vis));
        bool res=Travel(travel[i-1], travel[i]);
        if(!res){
            ans=true;
            return;
        }
    }
}

int main(){
    FAST;
    cin>>N>>cnt;
    int num;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>num;
            if(num==0) continue;
            connect[i].push_back(j);
            connect[j].push_back(i);
        }
    }
    for(int i=0; i<cnt; i++){
        cin>>num;
        travel.push_back(num);
    }
    Solve();
    if(ans) cout<<"NO"<<'\n';
    else cout<<"YES"<<'\n';
}
