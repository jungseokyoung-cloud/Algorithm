#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,ans;
int arr[15][15];
bool vis1[15]; // 열
bool vis2[35]; // 가로 1 (x+y)
bool vis3[35]; // 가로 2 (x-y+n-1)
void Move_Queen(int x, int y, bool res)
{
    vis1[y]=res;
    vis2[x+y]=res;
    vis3[x-y+N-1]=res;
}
void Solve_Queen(int x,int cnt)
{
    if(cnt==N)
    {
        ans++;
        return;
    }
    for(int i=0; i<N; i++)
    {
        if(!vis1[i] && !vis2[x+i] && !vis3[x-i+N-1])
        {
            Move_Queen(x,i,true);
            Solve_Queen(x+1, cnt+1);
            Move_Queen(x,i,false);
        }
    }
}

int main()
{
    FAST;
    cin>>N;
    Solve_Queen(0, 0);
    cout<<ans<<'\n';
}
