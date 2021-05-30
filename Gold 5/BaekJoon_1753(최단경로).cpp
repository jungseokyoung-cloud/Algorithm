#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 20001
int V,E,start_v;
int ans[MMAX];
vector<pair<int, int>> cost[MMAX];
void Find_min(int nd)
{
    priority_queue<pair<int, int>> pq;
    pq.push({ans[nd],nd});
    while(!pq.empty())
    {
        int c=-pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(int i=0; i<cost[node].size(); i++)
        {
            int ncost=cost[node][i].second;
            int nnode=cost[node][i].first;
            if(ans[nnode]>c+ncost)
            {
                ans[nnode]=c+ncost;
                pq.push({-ans[nnode],nnode});
            }
        }
    }
}
int main()
{
    cin>>V>>E>>start_v;
    fill(ans, ans+V+1, INT_MAX);
    ans[start_v]=0;

    int start,end,res;
    for(int i=0 ; i<E; i++) // 간선 입력
    {
        cin>>start>>end>>res;
        cost[start].push_back({end,res});
    }
  
    Find_min(start_v);
    for(int i=1; i<=V; i++)
    {
        if(ans[i]==INT_MAX)
            cout<<"INF"<<'\n';
        else
            cout<<ans[i]<<'\n';
    }
}
