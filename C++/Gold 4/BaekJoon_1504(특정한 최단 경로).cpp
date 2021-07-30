#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int V,E,V1,V2,res1,res2,Min;
vector<pair<int, int>> connect[801];
int ans[801];
bool vis[801][2]; // 0에는 V1방문 여부 1에는 V2 방문 여부
void Find_Min(int n){
    ans[n]=0;
    priority_queue<pair<int, int>>pos;
    pos.push({ans[n],n});
    bool vis1, vis2;
    while(!pos.empty()){
        vis1=false;
        vis2=false;
        int cost=-pos.top().first;
        int node = pos.top().second;
        pos.pop();
        if(node==V1)    vis1=true;
        else if(node == V2) vis2=true;
        for(int i=0; i<connect[node].size(); i++){
            int ncost=connect[node][i].second;
            int next=connect[node][i].first;
            if(ans[next]>ncost+cost){
                ans[next]=ncost+cost;
                pos.push({-ans[next],next});
            }
        }
    }
}
void Solve(int num, int target, int &res){  // 1 -> v1 -> v2 ->N 으로 가는 경우와 1-> v2 -> v1 -> N으로 가는 2가지의 경우가 있다.
    if(res!=INT_MAX){
        fill(ans, ans+801, INT_MAX);
        Find_Min(num);
        int com=ans[target];
        if(com==INT_MAX){
            res=INT_MAX;
            return;
        }
        res+=com;
    }
}

int main(){
    FAST;
    cin>>V>>E;
    int a,b,c;
    
    for(int i=0; i<E; i++){
        cin>>a>>b>>c;
        connect[a].push_back({b,c});
        connect[b].push_back({a,c});
    }
    cin>>V1>>V2;
    Solve(1, V1, res1);
    Solve(V1,V2,res1);
    Solve(V2, V, res1);
    Solve(1, V2, res2);
    Solve(V2, V1, res2);
    Solve(V1, V, res2);
    Min=min(res1, res2);
    if(Min==INT_MAX) cout<<"-1"<<'\n';
    else cout<<Min<<'\n';
}
