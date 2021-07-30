#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int lcs[1002][1002];
int main()
{
    FAST;
    int Max=0;
    string s1,s2;
    cin>>s1>>s2;
    for(int i=0; i<s1.size(); i++)
    {
        for(int j=0; j<s2.size(); j++)
        {
            if(s1[i]==s2[j])
            {
                lcs[i+1][j+1]=lcs[i][j]+1;
            }
            else
            {
                lcs[i+1][j+1]=max(lcs[i+1][j], lcs[i][j+1]);
            }
            if(lcs[i+1][j+1]>Max)
                Max=lcs[i+1][j+1];
        }
    }
    cout<<Max<<'\n';
}
