#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int main()
{
    FAST;
    int n;
    cin>>n;
    vector<int> v(n);
    vector<int> ans(n);
    fill(ans.begin(), ans.end(), 0);
    stack<pair<int, int>> st; //first는 비교할 수// secound는 인덱스
    for(int i=0; i<n; i++)
    cin>>v[i];
    int i=v.size()-1;
    while(i>=0)
    {
        if(!st.empty() && st.top().first<=v[i])
        {
            ans[st.top().second]=i+1;
            st.pop();
        }
        else
        {
            st.push({v[i],i});
            i--;
        }
    }
    for(int i=0; i<n; i++)
        cout<<ans[i]<<' ';
    cout<<'\n';
}
