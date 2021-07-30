#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,L,R,ans;
int arr[51][51];
int vis[51][51];
bool res;
int dis_x[]={1,0,-1,0};
int dis_y[]={0,1,0,-1};

void Move_Person(int x, int y)
{
    int add=arr[x][y];
    queue<pair<int, int>>pos;
    vector<pair<int, int>> nation;
    nation.push_back({x,y});
    pos.push({x,y});
    vis[x][y]=true;
    while(!pos.empty())
    {
        auto p=pos.front();
        pos.pop();
        for(int i=0; i<4; i++)
        {
            int nx=p.first+dis_x[i];
            int ny=p.second+dis_y[i];
            if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
            if(vis[nx][ny]) continue;
            int com=abs(arr[p.first][p.second]-arr[nx][ny]);
            if(L>com || R<com) continue;
            vis[nx][ny]=true;
            pos.push({nx,ny});
            add+=arr[nx][ny];
            res=true;
            nation.push_back({nx,ny});
        }
    }
    add/=nation.size();
    for(int i=0; i<nation.size(); i++)
    {
        arr[nation[i].first][nation[i].second]=add;
    }
}
void Check_Move()
{
    memset(vis, false, sizeof(vis));
    res=false;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(!vis[i][j])
                Move_Person(i,j);
        }
    }
    if(!res)
        return;
    ans+=1;
    return Check_Move();
}
int main()
{
    FAST;
    cin>>N>>L>>R;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        cin>>arr[i][j];
    }
    Check_Move();
    cout<<ans<<'\n';
}
