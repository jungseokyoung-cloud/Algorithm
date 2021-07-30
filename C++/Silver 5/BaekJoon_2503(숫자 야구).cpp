#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,strike,ball,strike_cnt,ball_cnt,ans=0;
    cin>>N;
    string s,s1;
    bool answer[1000];
    memset(answer, true, sizeof(answer));
    for(int i=123; i<=999; i++)
    {
        s=to_string(i);
        if(s[0]==s[1] || s[1]==s[2] || s[2]==s[0])
            answer[i]=false;
        if(s[0]=='0' || s[1]=='0' || s[2]=='0')
            answer[i]=false;
    }
    for(int i=0; i<N; i++)
    {
        cin>>s>>strike>>ball;
        for(int j=123; j<=999; j++)
        {
            ball_cnt=0;
            strike_cnt=0;
            if(answer[j])
            {
                s1=to_string(j);
                for(int k=0; k<3; k++)
                {
                    for(int x=0; x<3; x++)
                    {
                        if(s[x]==s1[k] && x==k)
                            strike_cnt++;
                        if(s[x]==s1[k]&& x!=k)
                            ball_cnt++;
                    }
                }
                if(ball_cnt!=ball || strike_cnt!=strike)
                    answer[j]=false;
            }
        }
    }
    for(int i=123; i<999; i++)
    {
        if(answer[i])
            ans++;
    }
    cout<<ans<<'\n';
}
