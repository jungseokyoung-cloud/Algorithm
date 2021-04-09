#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int result=s.size();
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='c')
        {
            if(s[i+1]=='=')
            {
                i++;
                result-=1;
            }
            else if(s[i+1]=='-')
            {
                i++;
                result-=1;
            }
        }
       else if(s[i]=='d')
        {
            if(s[i+1]=='z')
            {
                if(s[i+2]=='=')
                {
                    i+=2;
                    result-=2;
                }
            }
           else if(s[i+1]=='=')
            {
                i++;
                result-=1;
            }
        }
        else if(s[i]=='l' || s[i]=='n')
        {
            if(s[i+1]=='j')
            {
                i++;
                result-=1;
            }
        }
        else if(s[i]=='z' || s[i]=='s')
        {
            if(s[i+1]=='=')
            {
                i++;
                result-=1;
            }
        }
        else if(s[i]=='=' || s[i]=='-')
            result-=1;
    }
    cout<<result<<'\n';
}
