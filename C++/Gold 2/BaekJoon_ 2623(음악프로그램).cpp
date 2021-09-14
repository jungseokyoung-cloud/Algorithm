#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N,M;
int isDgree[1001];
vector<int> graph[1001];
vector<int> ans;

void Input(){
    cin>>N>>M;
    for(int i = 0; i<M; i++){
        int num;
        cin>>num;
        int node1,node2;
        cin>>node1;
        for(int j = 1; j<num; j++){
            cin>>node2;
            isDgree[node2] ++;
            graph[node1].push_back(node2);
            node1 = node2;
        }
    }
}

void Solve(){
    queue<int> node;
    for(int i = 1; i<=N; i++){
        if(isDgree[i] == 0) node.push(i);
    }
    
    while(!node.empty()){
        int now = node.front();
        node.pop();
        ans.push_back(now);
        
        for(int i = 0; i<graph[now].size(); i++){
            int next = graph[now][i];
            
            isDgree[next]--;
            if(isDgree[next] == 0) node.push(next);
        }
    }
}

int main(){
    FAST;
    Input();
    Solve();
    if(ans.size() == N)
        for(auto res : ans) cout<<res<<endl;
    else cout<<"0"<<endl;
}
