#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int main()
{
    FAST;
    int n;
    cin>>n;
    vector<pair<int, int>>v(n+1); //first는 상담 기간 second는 받는 금액
    for(int i=1; i<=n; i++)
    cin>>v[i].first>>v[i].second;
    int ans[n+2];// i날짜에 퇴사했을때 벌어들이는 돈의 최댓값.
    memset(ans, 0, sizeof(ans));
    for(int i=n; i>0; i--)
    {
        if((i+v[i].first)>(n+1))
            ans[i]=ans[i+1];
        else
            ans[i]=max(ans[i+1], ans[i+v[i].first]+v[i].second);
    }
    cout<<ans[1]<<'\n';
}
