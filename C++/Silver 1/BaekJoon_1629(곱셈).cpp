#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
ll Multi(ll a,ll b, ll c)
{
    if(b==1)
        return a%c;
    ll res=Multi(a, b/2, c);
    res=res*res%c;
    if(b%2==0)
        return res;
    else
        return res*a%c;
}
int main()
{
    ll A,B,C;
    cin>>A>>B>>C;
    ll res=Multi(A, B, C);
    cout<<res<<'\n';
}
