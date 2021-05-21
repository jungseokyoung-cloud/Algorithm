#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
vector<char>node[27];
int N;
void Preorder_DFS(int now)
{
        char ans=now+'A';
    cout<<ans;
    for(int i=0; i<2; i++)
    {
        if(node[now][i]=='.') continue;
        int next=node[now][i]-'A';
        Preorder_DFS(next);
    }
}

void Inorder_DFS(int now)
{
    char ans=now+'A';
   if(node[now][0]!='.')
   {
       int next=node[now][0]-'A';
       Inorder_DFS(next);
   }
    cout<<ans;
    if(node[now][1]!='.')
    {
        int next=node[now][1]-'A';
        Inorder_DFS(next);
    }
}
void Postorder_DFS(int now)
{
    for(int i=0; i<2; i++)
    {
        if(node[now][i]=='.') continue;
        int next=node[now][i]-'A';
        Postorder_DFS(next);
    }
    char ans=now+'A';
    cout<<ans;
}
int main()
{
    FAST;
    cin>>N;
    char idx;
    char left,right;
    for(int i=0; i<N; i++)
    {
        cin>>idx>>left>>right;
        node[idx-'A'].push_back(left);
        node[idx-'A'].push_back(right);
    }
    Preorder_DFS(0);
    cout<<'\n';
    Inorder_DFS(0);
    cout<<'\n';
    Postorder_DFS(0);
    cout<<'\n';
}
