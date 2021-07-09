#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,M,X,res;
int arr[1001];
int ans[1001];
const int INF = INT_MAX;

vector<pair<int, int>> edge[1001];

void FindWay(int start){
    priority_queue<pair<int, int>> pos;
    pos.push({0,start});
    arr[start] = 0;
    
    while(!pos.empty()){
        int cost = -pos.top().first;
        int now = pos.top().second;
        pos.pop();
        for(int i = 0; i<edge[now].size(); i++){
            int next = edge[now][i].first;
            int add = edge[now][i].second;
            if(arr[next] > cost + add){
                arr[next] = cost + add;
                pos.push({-arr[next],next});
            }
        }
    }
    
}

void Solve(){
    fill(arr, arr+1001, INF);
    FindWay(X);
    for(int i = 1; i<=N; i++){
        ans[i] += arr[i];
    }
    
    for(int i = 1; i<=N; i++){
        fill(arr, arr+1001, INF);
        FindWay(i);
        ans[i] += arr[X];
        res = max(res, ans[i]);
    }
}

int main(){
    cin>>N>>M>>X;
    int start,end,cost;
    for(int i = 0; i < M; i++){
        cin>>start>>end>>cost;
        edge[start].push_back({end,cost});
    }
    Solve();
    cout<<res<<'\n';
}
