#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,M,Min=INT_MAX;
int vis[13];
int arr[51][51];
vector<pair<int, int>> chicken_house,house,chicken;
int dis_x[]={1,0,-1,0};
int dis_y[]={0,-1,0,1};
void DisTance()
{
    int res=0;
    for(int i=0; i<house.size(); i++)
    {
        int dis=INT_MAX;
        int x=house[i].first;
        int y=house[i].second;
        for(int j=0; j<chicken.size(); j++)
        {
            int cx=chicken[j].first;
            int cy=chicken[j].second;
            int compare=abs(x-cx)+abs(y-cy);
            if(compare<dis)
                dis=compare;
        }
        res+=dis;
    }
    if(Min>res)
        Min=res;
}
void Delete_Chicken(int idx, int cnt)
{
    if(cnt==M)
    {
        DisTance();
        return;
    }
    for(int i=idx; i<chicken_house.size(); i++)
    {
        if(!vis[i])
        {
            vis[i]=true;
            int x=chicken_house[i].first;
            int y=chicken_house[i].second;
            chicken.push_back({x,y});
            Delete_Chicken(i, cnt+1);
            vis[i]=false;
            chicken.pop_back();
            
        }
    }
}
int main()
{
    FAST;
    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]==2) chicken_house.push_back({i,j});
            else if(arr[i][j]==1) house.push_back({i,j});
        }
    }
    Delete_Chicken(0, 0);
    cout<<Min<<'\n';
}
