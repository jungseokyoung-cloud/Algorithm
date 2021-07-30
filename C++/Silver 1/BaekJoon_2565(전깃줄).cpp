#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int main()
{
    FAST;
    int n,max=0;
    cin>>n;
    vector<pair<int, int>>v(n);
    int lis_dp[101];
    fill(lis_dp, lis_dp+100, 1);
    for(int i=0; i<n; i++)
    cin>>v[i].first>>v[i].second;
    sort(v.begin(), v.end());
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(v[i].second >v[j].second && lis_dp[i]<lis_dp[j]+1)
                lis_dp[i]=lis_dp[j]+1;
        }
        if(max<lis_dp[i])
            max=lis_dp[i];
    }
    cout<<n-max<<'\n';
}
