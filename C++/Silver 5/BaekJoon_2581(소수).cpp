#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main()
{
    FAST;
    int m,n,res=0,min;
    cin>>m>>n;
    for(int i=m; i<=n; i++)
    {
        if(i>1)
        {
        int div=0;
        for(int j=2; j<i; j++)
        {
            if(i%j==0)
            {
                div++;
                break;
            }
        }
        if(div==0 && res==0)
            min=i;
        if(div==0)
            res+=i;
        }
    }
    if(res==0)
        cout<<"-1"<<'\n';
    else
    cout<<res<<'\n'<<min<<'\n';
}
