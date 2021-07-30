#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
vector<int>connect[51];
bool vis[51];
int frd;
void DFS(int start, int num)
{
   if(!vis[start])
   {
       frd++;
       vis[start]=true;
   }
    if(num==2) // 2가 되면 더이상 탐색할 필요 X
        return;
    for(int i=0; i<connect[start].size(); i++)
    {
        int next=connect[start][i];
      //  if(vis[next])continue;  --> 이거 넣으면 틀림 왜?
        DFS(next, num+1);
    }
}
int main()
{
    FAST;
    int N;
    cin>>N;
    string s;
    for(int i=0; i<N; i++)
    {
        cin>>s;
        for(int j=0; j<N; j++)
        {
            if(s[j]=='Y')
                connect[i].push_back(j);
        }
    }
    int Max=0;
    for(int i=0; i<N; i++)
    {
        frd=0;
        memset(vis, false, sizeof(vis));
        DFS(i, 0);
        Max=max(Max, frd-1); // 자기 자신은 빼주어여함.
    }
    cout<<Max<<'\n';
}
