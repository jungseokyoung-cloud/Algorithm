#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int main()
{
    FAST;
    int n,idx=0;;
    cin>>n;
    stack<int> s;
    vector<int> v(n);
    vector<char> ans;
    for(int i=0; i<n; i++) //수열을 입력받는다
    cin>>v[i];
    for(int i=1; i<=n; i++)
    {
        s.push(i);
        ans.push_back('+');
        while(1)
        {
            if(!s.empty() && v[idx]==s.top())
            {
                s.pop();
                ans.push_back('-');
                idx++;
            }
            else if(s.empty() || v[idx]!=s.top())
                break;
            }
    }
    if(s.empty())
    {
        for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<'\n';
    }
    else
        cout<<"NO"<<'\n';
}
