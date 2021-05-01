#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
ll Binary_Search(int target, vector<ll>&ref)
{
    ll start=1,mid;
    ll end=ref.back();
    int result;
    while(start<=end)
    {
        result=0;
        mid=(start+end)/2;
        for(int i=0; i<ref.size(); i++)
            result+=ref[i]/mid;
        if(result>=target)
            start=mid+1;
        else
            end=mid-1;
    }
    return end;
}
int main()
{
    FAST;
    int n,k;
    ll ans;
    cin>>k>>n;  //k는 랜선의 개수 n은 원하는 갯수
    vector<ll>v(k);
    for(int i=0; i<k; i++)
    cin>>v[i];
    sort(v.begin(), v.end());
    ans=Binary_Search(n, v);
    cout<<ans<<'\n';
}
