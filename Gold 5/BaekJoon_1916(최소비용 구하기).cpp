#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 1001
int low_cost[MMAX];
int bus[MMAX][MMAX];
bool vis[MMAX];
int N,M,start,arrived;
int Next_Node()
{
    int min_idx=-1;
    int Min=INT_MAX;
    for(int i=1; i<=N; i++)
    {
        if(!vis[i] && Min>low_cost[i])
        {
            Min=low_cost[i];
            min_idx=i;
        }
    }
    return min_idx;
}
void Find_Low_Cost(int node)
{
    vis[node]=true;
    for(int i=1; i<=N; i++)
    {
        if(bus[node][i]!=-1)
            low_cost[i]=min(bus[node][i]+low_cost[node],low_cost[i]);
    }
    int next=Next_Node();
    if(next==-1)
        return;
    Find_Low_Cost(next);
}

int main()
{
    FAST;
    memset(bus, -1, sizeof(bus));
    fill(low_cost, low_cost+MMAX, INT_MAX);
    cin>>N>>M;
    int s,e,cost;
    for(int i=0; i<M; i++)
    {
        cin>>s>>e>>cost;
        if(bus[s][e]!=-1)
            bus[s][e]=min(bus[s][e], cost);
        else
            bus[s][e]=cost;
    }
    cin>>start>>arrived;
    low_cost[start]=0;
    Find_Low_Cost(start);
    cout<<low_cost[arrived]<<'\n';
}
