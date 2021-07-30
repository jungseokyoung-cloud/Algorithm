#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 100001
int hideSeek[MMAX];
int path[MMAX];
int vis[MMAX];
int N,K;
vector<int> ans;

int Go(int i, int x){
    if(i == 0) return x+1;
    else if(i == 1) return x-1;
    else return x*2;
}

void Answer_Root(){
    int now = K;
    while(1){
        ans.push_back(now);
        
        if(now == path[now]) return;
        now = path[now];
        
    }
}

void Solve(){
    queue<int> pos;
    pos.push(N);
    vis[N] = 0;
    while(!pos.empty()){
        int now = pos.front();
        pos.pop();
        if(now == K){
            Answer_Root();
            return;
        }
        for(int i=0; i<3; i++){
            int next = Go(i, now);
            if(next > MMAX || next < 0) continue;
            if(vis[next] > -1) continue;
            vis[next] = vis[now] + 1;
            path[next] = now;
            pos.push(next);
        }
    }
}

int main(){
    fill(vis, vis+MMAX, -1);
    fill(path, path+MMAX, -1);
    FAST;
    cin>>N>>K;
    path[N] = N;
    Solve();
    cout<<vis[K]<<'\n';
    for(int i = ans.size()-1; i>=0; i--) cout<<ans[i]<<' ';
    cout<<'\n';
}
