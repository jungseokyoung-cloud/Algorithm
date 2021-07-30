#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 1001
int arr[MMAX];
int vis[MMAX];
int vis_2[MMAX];
int cnt;
void DFS(int idx)
{
    vis[idx]=true;
    int next=arr[idx];
    if(!vis[next])
        DFS(next);
    if(vis[next] && !vis_2[next])
    {
        cnt++;
    }
    vis_2[idx]=true;
}
int main()
{
    FAST;
    int T,N;
    cin>>T;
    while(T--)
    {
        cin>>N;
        cnt=0;
        memset(vis, false, sizeof(vis));
        memset(vis_2, false, sizeof(vis_2));
        for(int i=1; i<=N; i++)
        cin>>arr[i];
        for(int i=1; i<=N; i++)
        {
            if(!vis[i])
                DFS(i);
        }
        cout<<cnt<<'\n';
    }
}
