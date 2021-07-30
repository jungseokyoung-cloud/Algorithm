#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
void Show(int idx, string &s)
{
    for(int i=0; i<s.size(); i++)
    {
        if(i==idx)
        {
            cout<<"["<<s[i]<<"]";
        }
        else
            cout<<s[i];
    }
    cout<<'\n';
}
int main()
{
    FAST;
    int n,ans_idx;
    bool ans[26];
    memset(ans, true, sizeof(ans));
    cin>>n;
    string s;
    cin.ignore(1, '\n');
    while(n--)
    {
        bool loop=true;
        getline(cin, s);
        for(int i=0; i<s.size(); i++) //단어의 첫번째 검사
        {
            if(i==0 || s[i-1]==' ')
            {
                if(s[i]>='A' && s[i]<='Z')
                    ans_idx=s[i]-65;
               else if(s[i]>='a' && s[i]<='z')
                    ans_idx=s[i]-97;
                    if(ans[ans_idx])
                    {
                        ans[ans_idx]=false;
                        Show(i, s);
                        loop=false;
                        break;
                    }
            }
        }
        if(loop) //true라면 단어의 첫번째 글자를 단축키로 지정할 수 없을 경우
        {
            for(int i=0; i<s.size(); i++)
            {
                if(s[i]!=' ')
                {
                    if(s[i]>='A' && s[i]<='Z')
                        ans_idx=s[i]-65;
                   else if(s[i]>='a' && s[i]<='z')
                        ans_idx=s[i]-97;
                    if(ans[ans_idx])
                    {
                        ans[ans_idx]=false;
                        Show(i, s);
                        loop=false;
                        break;
                    }
                }
            }
        }
        if(loop)// true라면 단축기를 지정할 수 없는 경우
            cout<<s<<'\n';
    }
}
