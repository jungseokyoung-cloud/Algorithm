#include<iostream>
using namespace std;
int main()
{
    string s1;
    int cnt;
    while(1)
    {
        cnt=0;
        cin>>s1;
        if(s1[0]=='0')
            break;
        for(int i=0; i<s1.size()/2; i++)
        {
            if(s1[i]!=s1[s1.size()-i-1])
                cnt++;
        }
        if(cnt==0)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
}
