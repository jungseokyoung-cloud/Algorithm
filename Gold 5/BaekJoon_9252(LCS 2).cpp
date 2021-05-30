#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int lis[1001][1001];
string s1,s2;
int dis_x[]={-1,0,-1};
int dis_y[]={0,-1,-1};
vector<char> lis_ans;
void Find_Answer(int x, int y)
{
    if(lis[x][y]==0)
        return;
    for(int i=0; i<2; i++)
    {
        int nx=x+dis_x[i];
        int ny=y+dis_y[i];
        if(lis[nx][ny]==lis[x][y])
            return Find_Answer(nx, ny);
    }
    lis_ans.push_back(s2[y-1]);
    return Find_Answer(x+dis_x[2], y+dis_y[2]);
}
int main()
{
    FAST;
    cin>>s1>>s2;
    for(int i=0; i<s1.size(); i++)
    {
        for(int j=0; j<s2.size(); j++)
        {
            if(s1[i]==s2[j])
            {
                lis[i+1][j+1]=lis[i][j]+1;
            }
            else
            {
                lis[i+1][j+1]=max(lis[i][j+1], lis[i+1][j]);
            }
        }
    }
    int n1=s1.size();
    int n2=s2.size();
    Find_Answer(n1, n2);
    cout<<lis_ans.size()<<'\n';
    if(lis_ans.size()!=0)
    {
        for(int i=lis_ans.size()-1; i>=0 ; i--)
        {
            cout<<lis_ans[i];
        }
        cout<<'\n';
    }
}
