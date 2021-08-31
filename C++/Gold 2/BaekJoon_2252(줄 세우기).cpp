#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N,M;
int inDgree[32001];
vector<int> graph[32001];
vector<int> ans;

void Solve(){
    queue<int> node;
    for(int i = 1; i<=N; i++){
        if(inDgree[i] == 0) node.push(i);
    }
    
    while(!node.empty()){
        int now = node.front();
        node.pop();
        ans.push_back(now);
        
        for(int i = 0; i<graph[now].size(); i++){
            int next = graph[now][i];
            
            if(--inDgree[next] == 0) node.push(next);
        }
    }
}

int main(){
    FAST;
    cin>>N>>M;
    int node1,node2;
    while(M--){
        cin>>node1>>node2;
        graph[node1].push_back(node2);
        inDgree[node2]++;
    }
    Solve();
    for(auto res : ans) cout<<res<<' ';
    cout<<endl;
}
