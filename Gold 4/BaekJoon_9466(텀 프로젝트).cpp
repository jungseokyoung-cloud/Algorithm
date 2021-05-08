#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 100001
int vis[MMAX];
int vis_2[MMAX];
int cnt;
vector<int> connect(MMAX);

void DFS(int start)
{
    vis[start]=true;
    int nx=connect[start];
    if(!vis[nx])
        DFS(nx); //방문 하지 않았을 경우
    else if(vis[nx] && !vis_2[nx]) // 방문을 했을 경우 연결요소를 이루는지 체크한다.
    {
        int idx=nx;
        while(idx!=start)
        {
            cnt++;
            idx=connect[idx];
        }
        cnt++;
    }
    vis_2[start]=true;
}

int main()
{
    int T,N;
    cin>>T;
    while(T--)
    {
        cnt=0;
        cin>>N;
        memset(vis_2, false, sizeof(vis_2));
        memset(vis, false, sizeof(vis));
        for(int i=1; i<=N; i++)
        {
            cin>>connect[i];
        }
        for(int i=1; i<=N; i++)
        {
            if(!vis[i])
                DFS(i);
        }
        cout<<N-cnt<<'\n';
    }
}
