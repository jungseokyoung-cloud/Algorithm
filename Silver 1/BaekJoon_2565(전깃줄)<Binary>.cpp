#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int Binary_Search(vector<int> &ref,int target)
{
    int start=0,end=ref.size()-1;
    int mid;
    while(start<end)
    {
        mid=(start+end)/2;
        if(ref[mid]<target)
            start=mid+1;
        else
            end=mid;
    }
    return end;
}
int main()
{
    FAST;
    int n;
    cin>>n;
    vector<pair<int, int>>v(n);
    vector<int> ans;
    for(int i=0; i<n; i++)
    cin>>v[i].first>>v[i].second;
    sort(v.begin(), v.end());
    ans.push_back(v[0].second);
    for(int i=1; i<n; i++)
    {
        if(ans.back()<v[i].second)
            ans.push_back(v[i].second);
        else
        {
            int idx=Binary_Search(ans, v[i].second);
            ans[idx]=v[i].second;
        }
    }
    cout<<n-ans.size()<<'\n';
}
