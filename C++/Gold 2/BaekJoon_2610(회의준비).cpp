#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N,M,cnt,minTime, minIdx;
const int INF = 1000000;
int floid[101][101];
vector<int> graph[101];
bool vis[101];
vector<int> ans;
void Input(){
    cin>>N>>M;
    for(int i = 1; i<=N; i++){
        fill(floid[i], floid[i] + 101, INF);
        floid[i][i] = 0;
    }
    while(M--){
        int node1,node2;
        cin>>node1>>node2;
        floid[node1][node2] = 1;
        floid[node2][node1] = 1;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
}

void Floid(){
    for(int k = 1; k<=N; k++){
        for(int i = 1; i<=N; i++){
            if(i == k) continue;
            
            for(int j = 1; j<=N; j++){
                if(k == j || i == j) continue;
                if(floid[i][j] > floid[i][k] + floid[k][j]) floid[i][j] = floid[i][k] + floid[k][j];
            }
        }
    }
}

int getMaxValue(int now){
    int value = -1;
    for(int i = 1; i<=N; i++){
        if(floid[now][i] >= INF) continue;
        value = max(value, floid[now][i]);
    }
    return value;
}

void DFS(int now){
    if(vis[now]) return;
    
    vis[now] = true;
    int value = getMaxValue(now);
    
    if(value < minTime){
        minTime = value;
        minIdx = now;
    }
    
    for(int i = 0; i<graph[now].size(); i++){
        int next = graph[now][i];
        DFS(next);
    }
}

void Solve(){
    Floid();
    for(int i = 1; i<=N; i++){
        if(vis[i]) continue;
        
        minTime = INF;
        DFS(i);
        ans.push_back(minIdx);
    }
    sort(ans.begin(), ans.end());
}

int main(){
    FAST;
    Input();
    Solve();
    
    cout<<ans.size()<<endl;
    for(auto res : ans) cout<<res<<endl;
}
