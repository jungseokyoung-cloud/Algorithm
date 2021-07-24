#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int INF = INT_MAX;
int N,M;
int ans[1001]; // 거리 저장
int path[1001]; // 경로 저장
vector<pair<int, int>> graph[1001];

void Print(int Start, int End){
    vector<int> res;
    int node = End;
    while(node != -1){
        res.push_back(node);
        node = path[node];
    }
    
    cout<<ans[End]<<'\n';
    cout<<res.size()<<'\n';
    for(int i = res.size()-1; i>=0; i--) cout<<res[i]<<' ';
    cout<<'\n';
}

void solve(int start){
    ans[start] = 0;
    path[start] = -1;
    
    priority_queue<pair<int, int>> node;
    node.push({0,start});

    while(!node.empty()){
        int cost = -node.top().first;
        int now = node.top().second;
        node.pop();
        
        if(ans[now] < cost) continue;
        for(int i = 0; i<graph[now].size(); i++){
            int next = graph[now][i].first;
            int add = graph[now][i].second;
            
            if(ans[next] > cost + add){
                ans[next] = cost + add;
                path[next] = now;
                node.push({-ans[next], next});
            }
        }
    }
}

int main(){
    FAST;
    cin>>N>>M;
    
    fill(ans, ans+1001, INF);
    
    int node1,node2,cost;
    for(int i = 0; i<M; i++){
        cin>>node1>>node2>>cost;
        graph[node1].push_back({node2,cost});
    }
        
    cin>>node1>>node2;
    solve(node1);
    Print(node1, node2);
}
