#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
int main()
{
    FAST;
    int N;
    ll res;
    cin>>N;
    pair<ll, ll> ans[91];//first는 0으로 끝날 경우, secound는 1로 끝날 경우
    memset(ans, 0, sizeof(ans));
    ans[1].second=1;
    for(int i=2; i<=N; ++i) //만약 i-1자리수가 1로끝났다면 뒤에 0만 올수 있다. 하지만 0으로 끝날경우 0과 1을 붙일수 있다.
    {
        ans[i].first=ans[i-1].first+ans[i-1].second; //i-1번째가 0으로 끝날 경우와 1로 끝날 경우(둘다 0이 올수 있음.)
        ans[i].second=ans[i-1].first;
    }
    res=ans[N].first+ans[N].second;
    cout<<res<<'\n';
}
