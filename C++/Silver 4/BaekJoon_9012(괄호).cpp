#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int j=0; j<n; j++)
    {
        string s;
        int cnt=0;
        cin>>s;
        bool ans[s.size()];
        bool result;
        memset(ans, true, sizeof(ans));
        for(int i=0;i<s.size(); i++)
        {
            if(s[i]=='(' && ans[i]){
                for(int k=i+1; k<s.size(); k++)
                {
                    if(s[k]==')' && ans[k])
                    {
                        ans[i]=false;
                        ans[k]=false;
                        cnt++;
                        break;
                    }
                }
            }
        }
        if(cnt*2==s.size())
            cout<<"YES"<<'\n';
        else
            cout<<"NO"<<'\n';
    }
}
