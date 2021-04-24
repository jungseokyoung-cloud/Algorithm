#include<iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int main()
{
    FAST;
    long long ans[1001]={0,};
    int n;
    cin>>n;
    ans[1]=1; ans[2]=2;
    for(int i=3; i<=n; i++)
        ans[i]=(ans[i-1]+ans[i-2])%10007;// i-1에서 2*1타일 추가 i-2에서 1*2타일 2개 추가하는법.
    cout<<ans[n]<<'\n';
}
