#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int main()
{
    FAST;
    int n,max=1;
    cin>>n;
    vector<int>v(n);
    vector<int>ans(n,1);
    for(int i=0; i<n; i++)
    cin>>v[i];
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(v[i]<v[j] && ans[i]<ans[j]+1) //감소 수열.
                ans[i]=ans[j]+1;
        }
        if(max<ans[i])
            max=ans[i];
    }
    cout<<max<<'\n';
}
