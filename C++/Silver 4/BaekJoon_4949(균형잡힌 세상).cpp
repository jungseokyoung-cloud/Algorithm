#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int main()
{
    FAST;
    string s;
    while(1)
    {
        int cnt=0;
        stack<char>n;
        stack<char>num;
        getline(cin, s);
        if(s==".")
            break;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(' || s[i]=='[')
            {
                n.push(s[i]);
                num.push(s[i]);
            }
            else if(s[i]==')' || s[i]==']')
            {
                num.push(s[i]);
                if(!n.empty() && n.top() =='(' && s[i]==')')
                {
                    n.pop();
                    cnt++;
                }
                if(!n.empty() && n.top()=='[' && s[i]==']')
                {
                    n.pop();
                    cnt++;
                }
            }
        }
        if(n.empty() && cnt*2==num.size())
            cout<<"yes"<<'\n';
        else
            cout<<"no"<<'\n';
    }
}
