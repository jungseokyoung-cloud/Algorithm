#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int T,N,K,W;
int build[1001];
vector<int> graph[1001];
int inDgree[1001];
int ans[1001];

void Reset(){
    memset(inDgree, 0, sizeof(inDgree));
    memset(ans, 0, sizeof(ans));
    for(int i = 1; i<=N; i++) graph[i].clear();
}

void Solve(){
    queue<int> node;
    
    for(int i = 1; i<=N; i++){
        if(inDgree[i] == 0){
            node.push(i);
            ans[i] = build[i];
        }
    }
    
    while(!node.empty()){
        int now = node.front();
        node.pop();
        
        for(int j = 0; j< graph[now].size(); j++){
            int next = graph[now][j];
            ans[next] = max(ans[next], ans[now] + build[next]);
            if(--inDgree[next] == 0) node.push(next);
            
        }
    }
}


int main(){
    FAST;
    cin>>T;
    while(T--){
        cin>>N>>K;
        Reset();
        
        for(int i = 1; i<=N; i++) cin>>build[i];
        
        int node1,node2;
        for(int i = 0; i<K; i++){
            cin>>node1>>node2;
            graph[node1].push_back(node2);
            inDgree[node2]++;
        }
//        cout<<"끝"<<endl;
        cin>>W;
        Solve();
        cout<<ans[W]<<'\n';
    }
    
}
