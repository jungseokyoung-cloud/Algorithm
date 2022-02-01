#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
const int INF = INT_MAX;

int N,M,T,s,g,h;
vector<pair<int, int>> graph[2001];
int costSt[2001];
int costG[2001];
int costH[2001];
int costGH;
vector<int> desti;

void setting(){
    for(int i = 0; i<=2000; i++) graph[i].clear();
    fill(costSt, costSt + 2001, INF);
    fill(costG, costG + 2001, INF);
    fill(costH, costH + 2001, INF);
    desti.clear();
}

void input(){
    cin>>N>>M>>T;
    cin>>s>>g>>h;
    while (M--) {
        int st,en,cost;
        cin>>st>>en>>cost;
        graph[st].push_back({en,cost});
        graph[en].push_back({st,cost});
        if((st == g && en == h) || (st == h & en == g)) costGH = cost;
    }
    while (T--) {
        int node;
        cin>>node;
        desti.push_back(node);
    }
}

void dijstra(int st, int (&isCost)[2001]) {
    priority_queue<pair<int, int>> node;
    isCost[st] = 0;
    node.push({0, st});
    
    while(!node.empty()){
        int now = node.top().second;
        int cost = -node.top().first;
        
        node.pop();
        if(isCost[now] < cost) continue;

        for(int i = 0; i<graph[now].size(); i++){
            int next = graph[now][i].first;
            int add = graph[now][i].second;
            
            if(isCost[next] <= cost + add) continue;

            isCost[next] = cost + add;
            node.push({-isCost[next], next});
        }
    }
}

void solve() {
    dijstra(s, costSt);
    dijstra(g, costG);
    dijstra(h, costH);
}

void print(){
    sort(desti.begin(), desti.end());
    for(int i = 0; i<desti.size(); i++){
        int destination = desti[i];
        int path1 = costSt[g] + costGH + costH[destination];
        int path2 = costSt[h] + costGH + costG[destination];

        if(costSt[destination] == INF) continue;
        if(path1 == costSt[destination] || path2 == costSt[destination]) cout<<destination<<' ';
    }
    cout<<endl;
}

int main(){
    FAST;
    int testCase;
    cin>>testCase;
    
    while(testCase--){
        setting();
        input();
        solve();
        print();
    }
}
