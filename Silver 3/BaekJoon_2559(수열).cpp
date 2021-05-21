#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int main()
{
    FAST;
    int n,k,max=0;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
        if(i<k)
            max+=v[i];
    }
    int sum=max;
    for(int i=k; i<n; i++)
    {
        sum+=v[i];
        sum-=v[i-k];
        if(sum>max)
            max=sum;
    }
    cout<<max<<'\n';
}
