#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int main()
{
    FAST;
    int n,max=0,compare;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++)
    cin>>v[i];
    int ans[1001];
    int decre[1001];
    for(int i=0; i<n; i++)
    {
        ans[i]=1;
        for(int j=0; j<i; j++)
        {
            if(v[i]>v[j] && ans[i]<ans[j]+1)
                ans[i]=ans[j]+1;
        }
    }
    for(int i=n-1; i>=0; i--) //감소 하는 부분.
    {
        decre[i]=1;
        for(int j=n-1; j>i; j--)
        {
            if(v[i]>v[j] && decre[i]<decre[j]+1)
                decre[i]=decre[j]+1;
        }
        if(max<(ans[i]+decre[i]-1))
            max=ans[i]+decre[i]-1;
    }
    cout<<max<<'\n';
}
