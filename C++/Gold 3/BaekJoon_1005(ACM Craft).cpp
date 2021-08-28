#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int T, N, K, W;
int inDgree[1001];
int value[1001];
int res[1001];
vector<int> graph[1001];

void Setting(){
    fill(inDgree, inDgree + 1001, 0);
    for(int i = 1; i<=N; i++) graph[i].clear();
    fill(res, res + 1001, 0);
}

void Input(){
    cin>>N>>K;
    for(int i = 1; i<=N; i++) cin>>value[i];
    
    int node1,node2;
    while(K--){
        cin>>node1>>node2;
        graph[node1].push_back(node2);
        inDgree[node2] ++;
    }
    cin>>W;
}

void Solve(){
    queue<int> node;
    for(int i = 1; i<=N; i++){
        if(inDgree[i] == 0){
            node.push(i);
            res[i] = value[i];
        }
    }
    
    while(!node.empty()){
        int now = node.front();
        node.pop();
        if(now == W) return;
        for(int i = 0; i<graph[now].size(); i++){
            int next = graph[now][i];
            
            res[next] = max(res[next], res[now] + value[next]);
            if( --inDgree[next] == 0) node.push(next);
        }
    }
}

int main(){
    FAST;
    cin>>T;
    
    while(T--){
        Setting();
        Input();
        Solve();
        cout<<res[W]<<endl;
    }
}
