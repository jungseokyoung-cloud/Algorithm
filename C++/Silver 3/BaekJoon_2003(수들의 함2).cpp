#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int main()
{
    FAST;
    int n,m,cnt=0,end=0,sum=0,start=0;
    cin>>n>>m;
    vector<int>v(n);
    for(int i=0; i<n; i++) //수열을 입력받음.
    cin>>v[i];
    while(end<=n)
    {
        if(sum>m) // sum이 m보다 크다면 start를 증가해야함.
        {
            sum-=v[start];
            start++;
        }
        else if(sum<m)
        {
            sum+=v[end];
            end++;
        }
        else if(sum==m)
        {
            cnt++;
            sum-=v[start];
            start++;
        }
    }
    cout<<cnt<<'\n';
}
