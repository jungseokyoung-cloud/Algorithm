#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int main()
{
    int t,n;
    cin>>t;
    for(int j=0; j<t; j++)
    {
        long long p[101]={0,};
        cin>>n;
        p[1]=1;
        p[2]=1;
        p[3]=1;
        p[4]=2;
        p[5]=2;
        for(int i=6; i<=n; i++)
        {
            p[i]=p[i-1]+p[i-5];
        }
        cout<<p[n]<<'\n';
    }
}
