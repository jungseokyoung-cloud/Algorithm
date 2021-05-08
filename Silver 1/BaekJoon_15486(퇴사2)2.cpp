#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int main()
{
    FAST;
    int n;
    cin>>n;
    vector<pair<int, int>>v(n+1);
    for(int i=1; i<=n; i++)
    cin>>v[i].first>>v[i].second;
    vector<int>ans(n+2);
    fill(ans.begin(), ans.end(), 0);
    int current_max=0;
    for(int i=1; i<=n+1; i++)
    {
        current_max=max(ans[i], current_max);
        if(v[i].first+i>n+1)
            continue;
        else
        {
            ans[i+v[i].first]=max(ans[i+v[i].first], v[i].second+current_max);
        }
    }
    cout<<current_max<<'\n';
}
