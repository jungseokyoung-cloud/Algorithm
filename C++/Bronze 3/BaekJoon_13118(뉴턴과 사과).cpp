#include<iostream>
using namespace std;

int main()
{
    int p1,p2,p3,p4;
    int cnt=0;
    cin>>p1>>p2>>p3>>p4;
    int x,y,r;
    cin>>x>>y>>r;
    if(p1==x)
    {
        cout<<1<<endl;
        cnt++;
    }
    if(p2==x)
    {
        cout<<2<<endl;
        cnt++;
    }
    if(p3==x)
    {
        cout<<3<<endl;
        cnt++;
    }
    if(p4==x)
    {
        cout<<4<<endl;
        cnt++;
    }
    if(cnt==0)
        cout<<0<<endl;
}
