#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,cnt=1,cnt_max=1;
    cin>>n;
    long long ans;
    vector<long long> v(n,0);
    for(int i=0; i<n; i++)
    cin>>v[i];
    sort(v.begin(), v.end());
    ans=v[0];
    for(int i=1; i<n; i++)
    {
        if(v[i-1]==v[i])
            cnt++;
        if(v[i-1]!=v[i] ||i==n-1) //마지막까지 검사 깔꼼하게
        {
            if(cnt_max<cnt)
            {
                cnt_max=cnt;
                ans=v[i-1];
            }
            cnt=1;
        }
    }
    cout<<ans<<'\n';
}
