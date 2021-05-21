#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int main()
{
    FAST;
    int t;
    cin>>t;
    string s_long,s_short,s3;
    while(t--)
    {
        bool zero=false,zero2=false;
        cin>>s_long>>s_short;
        if(s_long.size()<s_short.size())  //s_long에 긴것을 저장함.
        {
            s3=s_long;
            s_long=s_short;
            s_short=s3;
        }
        reverse(s_long.begin(), s_long.end());
        reverse(s_short.begin(), s_short.end());
        for(int i=0; i<s_long.size(); i++)
        {
            if(i<s_short.size())
                s_long[i]+=(s_short[i]-'0');
            if(s_long[i]>'1')
            {
                s_long[i]-=2;
                if(i==s_long.size()-1)
                    s_long+='1';
                else
                    s_long[i+1]+=1;
            }
            if(s_long[i]=='1') // 모두다 0이 라면 0 하나만 출력해야함
                zero2=true;
        }
        reverse(s_long.begin(), s_long.end());
        if(zero2)
        {
            for(auto c: s_long)
            {

                if(!zero)
                {
                    if(c=='1')
                        zero=true;
                }
                if(zero)
                    cout<<c;
            }
        }
        else
            cout<<"0";
        cout<<'\n';
    }
}
