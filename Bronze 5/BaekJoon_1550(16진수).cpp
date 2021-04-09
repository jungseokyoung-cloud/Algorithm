#include <iostream>
#include<cstring>
using namespace std;

int main()
{
    string s1;
    cin>>s1;
    long long temp=1;
    long long sum=0;
    int num=s1.length();
    for(int i=num-1; i>=0; i--)
    {
        if(s1[i]=='A')
        {
            sum+=10*temp;
        }
        if(s1[i]=='B')
        {
           sum+= 11*temp;
        }
        if(s1[i]=='C')
        {
            sum+=12*temp;
        }
        if(s1[i]=='D')
        {
           sum+= 13*temp;
        }
        if(s1[i]=='E')
        {
            sum+=14*temp;
        }
        if(s1[i]=='F')
        {
            sum+=15*temp;
        }
        if(s1[i]>='0' && s1[i]<='9')
            sum+=(s1[i]-'0')*temp;
        temp*=16;
    }
    cout<<sum<<endl;
}
