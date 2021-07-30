#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
vector<int> cost;
ll ans;
int node_num,high;
void Solve(int parent){
    int child=parent*2;
    if(child>=cost.size()) {
        return;
    }
    
    Solve(child);
    Solve(child+1);
    
    int comp=abs(cost[child]-cost[child+1]);
    
    if(cost[child]>cost[child+1]) cost[child+1]+=comp;
    else cost[child]+=comp;
    cost[parent]+=cost[child];
    ans+=comp;
}

int main(){
    FAST;
    int n;
    cin>>high;
    for(int i=0; i<=high; i++)
        node_num+=1<<i;
    
    cost.push_back(-1); // 0번 인덱스 사용 X
    cost.push_back(0);
    for(int i=1; i<node_num; i++){
        cin>>n;
        cost.push_back(n);
        ans+=n;
    }
    Solve(1);
    cout<<ans<<'\n';
}
