#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 20002
pair<int, int> Heap[300001];
int ans[MMAX];
int idx,V,E,Start;
vector<pair<int, int>>connect[MMAX];
void Push_Heap(int cost, int node){
    int i=++idx;
    while(i!=1 && cost<Heap[i/2].first){
        Heap[i]=Heap[i/2];
        i/=2;
    }
    Heap[i]={cost,node};
}
void Pop_Heap(){
    int parent=1;
    Heap[1]=Heap[idx--];
    while(1){
        int child=parent*2;
        if(child+1<=idx && Heap[child].first>Heap[child+1].first)
            child++;
        if(child>idx || Heap[child].first>Heap[parent].first) return;
        swap(Heap[child], Heap[parent]);
        parent=child;
    }
}
void Solve(){
    Push_Heap(ans[Start], Start);
    while(idx>0){
        int cost=Heap[1].first;
        int now=Heap[1].second;
        Pop_Heap();
        for(int i=0; i<connect[now].size(); i++){
            int ncost=connect[now][i].first;
            int next=connect[now][i].second;
            if(ans[next]>cost+ncost){
                ans[next]=cost+ncost;
                Push_Heap(ans[next], next);
            }
        }
    }
}
int main(){
    FAST;
    cin>>V>>E>>Start;
    fill(ans, ans+MMAX, INT_MAX);
    ans[Start]=0;
    
    int u,v,w;
    for(int i=0; i<E; i++){
        cin>>u>>v>>w;
        connect[u].push_back({w,v});
    }
    
    Solve();
    
    for(int i=1; i<=V; i++)
    {
        if(ans[i]==INT_MAX)
            cout<<"INF"<<'\n';
        else
            cout<<ans[i]<<'\n';
    }
}
