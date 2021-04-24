#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int main()
{
    int dp[1000001]={0,};
    FAST;
    int n;
    cin>>n;
    for(int i=2; i<=n; i++)
    {
        dp[i]=dp[i-1]+1; //전 단계에서 일을 더함.
        if(i%2==0)
            dp[i]=min(dp[i], dp[i/2]+1); //전단계에서 1을 더한것과 i/2에서 2를 곱한것중 누가 더 작은지 비교함.
        if(i%3==0)
            dp[i]=min(dp[i],dp[i/3]+1); //전단게에서 1을 더한 것과 i/3에서 3을 곱한것중 누가 더 작은지 비교함.
    }
    cout<<dp[n]<<'\n';
}
