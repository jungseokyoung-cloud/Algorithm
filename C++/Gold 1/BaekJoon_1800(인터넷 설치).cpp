#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N,P,K;
vector<pair<int, int>> graph[1001];

void init() {
    cin>>N>>P>>K;
    for(int i = 0; i<P; i++){
        int n1,n2,cost;
        cin>>n1>>n2>>cost;
        graph[n1].push_back({n2, cost});
        graph[n2].push_back({n1, cost});
    }
}

bool canGo(int mid) {
    int dist[N+1];
    fill(dist, dist + N + 1, INT_MAX);
    
    priority_queue<pair<int, int>> pq;
    dist[1] = 0;
    pq.push({0,1});
    
    while(!pq.empty()) {
        int cnt = -pq.top().first;
        int now = pq.top().second;
        
        pq.pop();
        if(cnt < dist[now]) continue;
        
        for(int i = 0; i<graph[now].size(); i++) {
            int next = graph[now][i].first;
            int cost = graph[now][i].second;
            int nextCnt = cnt;
            
            if(cost > mid) nextCnt ++;
            if(nextCnt >= dist[next]) continue;
            
            dist[next] = nextCnt;
            pq.push({-nextCnt, next});
        }
    }
    
    if(dist[N] > K) return false;
    else return true;
}

void solve() {
    int st = 0, en = 1000000;
    int res = -1;
    
    while(st < en) {
        int mid = (st + en) / 2;
        
        if(!canGo(mid)) st = mid + 1;
        else {
            en = mid;
            res = mid;
        }
    }
    cout<<res<<endl;
}

int main(){
    FAST;
    init();
    solve();
}
