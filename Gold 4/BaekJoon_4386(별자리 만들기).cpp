#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N;
float cost;
vector<pair<float, float>> star;
vector<pair<float, float>>vis;
vector<pair<float, float>>unvis;
float Calculate(float x, float y, float nx, float ny){
    float dis = (x-nx)*(x-nx) + (y-ny)*(y-ny);
    dis = sqrt(dis);
    return dis;
}
void Prim(){
    for(int i=1; i<N; i++){
        float minCost = FLT_MAX;
        int min_idx=-1;
        for(int j=0; j<i; j++){
            for(int k=0; k<N-i; k++){
                float comp = Calculate(vis[j].first, vis[j].second, unvis[k].first, unvis[k].second);
                if(comp < minCost){
                    minCost = comp;
                    min_idx = k;
                }
            }
        }
        vis.push_back({unvis[min_idx].first, unvis[min_idx].second});
        unvis.erase(unvis.begin() + min_idx);
        cost += minCost;
    }
}

int main(){
    FAST;
    cin>>N;
    for(int i=0; i<N; i++){
        float x,y;
        cin>>x>>y;
        if(i==0) vis.push_back({x,y});
        else unvis.push_back({x,y});
    }
    Prim();
    cost = trunc(cost * 100);
    cout<<cost/100<<'\n';
}
