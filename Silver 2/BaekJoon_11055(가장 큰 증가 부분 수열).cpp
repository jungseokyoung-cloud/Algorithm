#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int ans[1001];
int main()
{
    FAST;
    int n,res=0;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
        ans[i]=v[i];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(v[i]>v[j])
                ans[i]=max(ans[i], ans[j]+v[i]);
        }
        if(res < ans[i])
            res=ans[i];
    }
    cout<<res<<'\n';
}
