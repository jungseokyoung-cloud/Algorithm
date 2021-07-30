#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int main()
{
    FAST;
    int n,max=1;
    cin>>n;
    vector<int>v(n);
    vector<int>ans(n,1); //ans[i]는 v[i]가 마지막으로 들어가는 수열중 가장 긴 수열의 길이임.
    for(int i=0; i<n; i++)
        cin>>v[i];
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(v[i]>v[j] && ans[i]<ans[j]+1) //i의 원소가 j의 원소보다 작다면 이것은 증가 수열이다.
                ans[i]=ans[j]+1;
        }
        if(ans[i]>max)
          max=ans[i];
    }
    cout<<max<<'\n';
}
