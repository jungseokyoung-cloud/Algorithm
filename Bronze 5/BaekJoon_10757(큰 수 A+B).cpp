#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    if(s2.size()>s1.size())
    {
        string temp;
        temp=s1;
        s1=s2;
        s2=temp;
    }
    for(int i=0; i<s1.size(); i++)
    {
        if(i<s2.size())
            s1[i]+=(s2[i]-'0');
        if(s1[i]>'9')
        {
            s1[i]-=10;
            if(i==s1.size()-1)
                s1+='1'; //문자열 추가함
            else
                s1[i+1]+=1;
        }
    }
    reverse(s1.begin(), s1.end());
    cout<<s1<<'\n';
}
