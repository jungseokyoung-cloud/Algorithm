#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,M;
vector<int> ans;
bool vis[9];
void Show_arr(){
    for(int i=0; i<ans.size(); i++)
    cout<<ans[i]<<' ';
    cout<<'\n';
}
void DFS(int cnt){
    if(cnt==M)
    {
        Show_arr();
        return;
    }
    
    for(int i=1; i<=N; i++)
    {
        if(!vis[i])
        {
            vis[i]=true;
            ans.push_back(i);
            DFS(cnt+1);
            vis[i]=false;
            ans.pop_back();
        }
    }
}
int main()
{
    FAST;
    cin>>N>>M;
    DFS(0);
}
