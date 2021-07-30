#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 501
int N,M,K,T;
vector<int> graph[MMAX];
int ans[2000];
bool vis[MMAX];
bool finished[MMAX];
bool cycle;

void ForCycle(){
    memset(vis, false, sizeof(vis));
    memset(finished, false, sizeof(finished));
    cycle = false;
}

void Setting(){
    for(int i = 0; i<MMAX; i++) graph[i].clear();
}

void FindCycle(int node){
    if(cycle) return;
    vis[node] = true;
    for(int i = 0; i<graph[node].size(); i++){
        int next = graph[node][i];
        if(!vis[next]) FindCycle(next);
        else if(!finished[next]){
            cycle = true;
            return;
        }
    }
    finished[node] = true;
}

void Solve(int node1, int node2, int idx){
    ForCycle();
    graph[node1].push_back(node2);
    FindCycle(node1);
    if(!cycle) ans[idx] = 0;
    else{
        graph[node1].pop_back();
        graph[node2].push_back(node1);
        ans[idx] = 1;
    }
}

int main(){
    FAST;
    cin>>T;
    for(int t = 1; t<=T; t++){
        cin>>N>>M>>K;
        int start, end;
        Setting();
        for(int i = 0; i<M; i++){
            cin>>start>>end;
            graph[start].push_back(end);
        }
        for(int i = 0; i<K; i++){
            cin>>start>>end;
            Solve(start, end, i);
        }
        cout<<"Case #"<<t<<'\n';
        for(int i = 0; i<K; i++) cout<<ans[i];
        cout<<'\n';
    }
}
