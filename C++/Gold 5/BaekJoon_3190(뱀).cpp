#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 101
int Dummy[MMAX][MMAX];
int dis_x[]={0,-1,0,1};
int dis_y[]={1,0,-1,0};
int N,sec,direction; //(0 오른쪽),(1 위쪽),(2 왼쪽),(3 아래)
deque<pair<int, int>> pos;
queue<pair<int, char>> change;
void DFS()
{
    if(!change.empty() && sec==change.front().first)
    {
        if(change.front().second=='D')
        {
            direction--;
            if(direction<0) direction+=4;
        }
        else if(change.front().second=='L')
        {
            direction++;
            if(direction>3) direction-=4;
        }
        change.pop();
    }
    sec++;
    auto head=pos.back();
    int next_x=head.first+dis_x[direction];
    int next_y=head.second+dis_y[direction];
    if(next_x<1 || next_x>N || next_y<1 || next_y>N ||Dummy[next_x][next_y]==1) return;
    pos.push_back({next_x,next_y});
    Dummy[head.first][head.second]=1;
    if(Dummy[next_x][next_y]==0)
    {
        Dummy[pos.front().first][pos.front().second]=0;
        pos.pop_front();
    }
    return DFS();
}
int main()
{
    FAST;
    int x,y,K,l,t;
    cin>>N>>K;
    for(int i=0; i<K; i++)
    {
        cin>>x>>y;
        Dummy[x][y]=2;
    }
    pos.push_back({1,1});
    char c;
    cin>>l;
    for(int i=0; i<l; i++)
    {
        cin>>t>>c;
        change.push({t,c});
    }
    DFS();
    cout<<sec<<'\n';
}
