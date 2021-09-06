#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N,M;
vector<int> graph[32001];
int isDgree[32001];
vector<int> ans;

void Input(){
    cin>>N>>M;
    int node1,node2;
    while(M--){
        cin>>node1>>node2;
        graph[node1].push_back(node2);
        isDgree[node2]++;
    }
}

void Solve(){
    priority_queue<int> node;

    for(int i = 1; i<=N; i++){
        if(isDgree[i] > 0) continue;
        node.push(-i);
    }
    while(!node.empty()){
        int now = -node.top();
        ans.push_back(now);
        node.pop();
        
        for(int i = 0; i<graph[now].size(); i++){
            int next = graph[now][i];
            
            if(--isDgree[next] == 0) node.push(-next);
        }
    }
}

int main(){
    FAST;
    Input();
    Solve();
    for(auto res : ans) cout<<res<<' ';
    cout<<endl;
}
