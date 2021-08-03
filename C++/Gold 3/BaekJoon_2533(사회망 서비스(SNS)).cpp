#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define MMAX 1000001
int N,ans;
int DP[MMAX][2];
//bool vis[MMAX];
vector<int> graph[MMAX];

int DFS(int now, int par, int state){ // 1이면 얼리임 0이 아니면 얼리가 아님
    int &ref = DP[now][state]; // 현재노도의 상태가 state일때의 얼리 의 최소갯수
    
    if(ref != -1) return ref;
    
    ref = 0;
    
    for(int i = 0; i<graph[now].size(); i++){
        int next = graph[now][i];
        if(next == par) continue;
        
        int temp = INT_MAX;
        
        temp = min(temp, DFS(next, now, 1));
        if(state == 1) temp = min(temp, DFS(next, now, 0));
        ref += temp;
    }

    return ref += state;
}

void Solve(){
    memset(DP, -1, sizeof(DP));
    ans = INT_MAX;
    ans = min(DFS(1, -1, 0), ans);
    ans = min(DFS(1, -1, 1), ans);
}

int main(){
    FAST;
    cin>>N;
    int u,v;
    for(int i = 1; i<N; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    Solve();
    cout<<ans<<endl;
}
