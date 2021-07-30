#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int main(){
    FAST;
    string s;
    cin>>s;
    int compare=1,sum=0;
    bool ans=true;
    stack<char> st;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='(')
        {
            compare*=2;
            st.push(s[i]);
        }
        else if(s[i]=='[')
        {

            compare*=3;
            st.push(s[i]);
        }
        else if(s[i]==']')
        {
            if(st.empty() || st.top()!='[')
            {
                ans=false;
                break;
            }
            else if(s[i-1]=='[')
                sum+=compare;
            compare/=3;
            st.pop();
        }
        else if(s[i]==')')
        {
            if(st.empty() || st.top()!='(')
            {
                ans=false;
                break;
            }
            else if(s[i-1]=='(')
                sum+=compare;
            compare/=2;
            st.pop();
        }
    }
    if(ans && st.empty())
        cout<<sum<<'\n';
    else
        cout<<"0"<<'\n';
}
