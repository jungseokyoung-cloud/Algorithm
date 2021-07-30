#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n,cnt=0,common_diff;
    bool ans=true;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        s=to_string(i);
        if(s.size()<3)
            cnt++;
        else
        {
            common_diff=(int)s[0]-(int)s[1];
            for(int j=2; j<s.size(); j++)
            {
                if((s[j-1]-s[j])==common_diff)
                    ans=true;
                else
                {
                    ans=false;
                    break;
                }
            }
            if(ans)
                cnt++;
        }
    }
    cout<<cnt<<'\n';
}
