#include <iostream>
#include <vector>
#include<algorithm>
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 100001
using namespace std;
struct Edge{
    int child,cost;
};
int ans,N,temp;
vector<Edge> connect[MMAX];
bool comp(int a, int b){
    return a>b;
}

void DFS(int node, int total){
    if(connect[node].size()==0){
        temp=max(temp, total);
    }
    for(int i=0; i<connect[node].size(); i++){
        int next=connect[node][i].child;
        int cost=connect[node][i].cost;
        DFS(next, cost+total);
    }
}

void Solve(){
    for(int i=1; i<=N; i++){
        if(connect[i].size()==0)    continue;
        vector<int> res;
        for(int j=0; j<connect[i].size(); j++){
            temp=0;
            DFS(connect[i][j].child, connect[i][j].cost);
            res.push_back(temp);
        }
        if(connect[i].size()>1){
        sort(res.begin(), res.end(), comp);
        ans=max(ans, res[0]+res[1]);
        }
        else{
            ans=max(ans,res[0]);
        }
        
    }
}

int main(){
    FAST;
    cin>>N;
    int parent, child1, cost1;
    for(int i=1; i<N; i++){
        cin>>parent>>child1>>cost1;
        connect[parent].push_back({child1,cost1});
    }
    
    Solve();
    cout<<ans<<'\n';
}
