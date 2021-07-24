#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 501
int N;
int isDgree[MMAX];
int cost[MMAX];
vector<int> graph[MMAX];
int root;
int ans[MMAX];

void Input(){
    cin>>N;
    for(int i = 1; i<=N; i++){
        cin>>cost[i];
        while(1){
            int num;
            cin>>num;
            if(num == -1) break;
            isDgree[i] ++;
            graph[num].push_back(i);
        }
    }
}

void Solve(){
    queue<int> node;
    for(int i = 1; i<=N; i++){
        if(isDgree[i] == 0){
            node.push(i);
            ans[i] = cost[i];
        }
            
    }
    
    while(!node.empty()){
        int now = node.front();
        node.pop();
        
        for(int i = 0; i<graph[now].size(); i++){
            int next = graph[now][i];
            
            ans[next] = max(ans[next], ans[now] + cost[next]);
            
            if(--isDgree[next] == 0) node.push(next);
            
        }
    }
}

void Print(){
    for(int i = 1; i<=N; i++) cout<<ans[i]<<'\n';
}

int main(){
    FAST;
    Input();
    Solve();
    Print();
}
