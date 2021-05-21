#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 1001
#define ll long long
ll arr[MMAX][10];
int main()
{
    FAST;
    int N;
    cin>>N;
    for(int i=0; i<10; i++)
    {
        arr[1][i]=1;
    }
    for(int i=2; i<=N; i++)
    {
        for(int j=0; j<10; j++)
        {
            for(int k=0; k<=j; k++)
            {
                arr[i][j]+=(arr[i-1][k]%10007);
            }
        }
    }
    ll ans=0;
    for(int i=0; i<10; i++)
    {
        ans+=arr[N][i];
    }
    cout<<ans%10007<<'\n';
}
