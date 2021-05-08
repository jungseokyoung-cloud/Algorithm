#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int Binary_Search(vector<int>&ref, int target)
{
    int start=0,end=ref.size()-1,mid;
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
    vector<int>v(n);
    vector<int>ans;
    for(int i=0; i<n; i++)
    cin>>v[i];
    ans.push_back(v[0]);
    for(auto i : v)
    {
        if(i>ans.back())
            ans.push_back(i);
        else
        {
            int idx=Binary_Search(ans, i);
            ans[idx]=i;
        }
    }
    cout<<ans.size()<<'\n';
}
