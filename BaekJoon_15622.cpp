#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1;
    cin>>s1;
    int time=0;
    for(int i=0; i<s1.size(); i++)
    {
        if(s1[i]<='O')
            time+=(s1[i]-65)/3+3;
        else if(s1[i]<='S' && s1[i]>='P')
            time+=8;
        else if(s1[i]<='V' && s1[i]>='T')
            time+=9;
        else
            time+=10;
    }
    cout<<time<<endl;
}
