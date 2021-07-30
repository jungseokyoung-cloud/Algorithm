#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    FAST;
    int start,end,result=0,d;
    cin>>start>>end>>d;
    bool answer[end+1];
    memset(answer, true, sizeof(answer));
    string s;
    for(int i=2; i<=end; i++)
    {
        if(answer[i])
        {
            if(i>=start)
            {
                s=to_string(i);
                for(int k=0; k<s.size(); k++)
                {
                    if(s[k]==(d+'0'))
                    {
                        result++;
                        break;
                    }
                }
            }
            for(int j=1; (j*i)<=end; j++)
            {
                 if(answer[i*j])
                    answer[i*j]=false;
            }
        }
    }
    cout<<result<<'\n';
}
