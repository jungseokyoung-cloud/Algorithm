#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
int main()
{
    FAST;
    ll N,sum=0; //빌딩의 개수
    cin>>N;
    vector<int>v(N);
    for(int i=0; i<N; i++)
    cin>>v[i];
    stack<int> st;
    for(int i=0; i<v.size(); i++)
    {
        while(!st.empty() && st.top()<=v[i])
        {
            st.pop();
        }
        st.push(v[i]);
        sum+=(st.size()-1);
    }
    cout<<sum<<'\n';
}
