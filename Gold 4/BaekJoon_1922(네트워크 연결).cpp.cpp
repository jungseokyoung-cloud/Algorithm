#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int V,E,ans;
int connect[1001][1001];
vector<int>vis,unvis;

void Prim(int start){
    vis.push_back(start);
    for(int i=1; i<=V; i++){
        if(i==start) continue;
        unvis.push_back(i);
    }
    
    for(int i=1; i<V; i++){
        int Min=INT_MAX;
        int min_idx=0;
        for(int j=0; j<i; j++){
            for(int k=0; k<V-i; k++){
                if(connect[vis[j]][unvis[k]]>0 && Min>connect[vis[j]][unvis[k]]){
                    Min=connect[vis[j]][unvis[k]];
                    min_idx=k;
                }
            }
        }
            vis.push_back(unvis[min_idx]);
            unvis.erase(unvis.begin()+min_idx);
            ans+=Min;
    }
}

int main(){
    FAST;
    cin>>V>>E;
    int a,b,c;
    for(int i=0; i<E; i++){
        cin>>a>>b>>c;
        connect[a][b]=c;
        connect[b][a]=c;
    }
    Prim(1);
    cout<<ans<<'\n';
}
