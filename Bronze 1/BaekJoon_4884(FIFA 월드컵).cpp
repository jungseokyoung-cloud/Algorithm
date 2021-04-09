#include <iostream>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main()
{
    FAST;
    long long int g,t,a,d;
    while(1)
    {
        long long int x=0,y=0,n=1;
    cin>>g>>t>>a>>d;
        if(g==-1 && t==-1&&a==-1&&d==-1)
            break;
    long long int tonner=(g*a)+d;
        x=g*t*(t-1)/2;
        while(tonner>n)
        {
            x+=n;
            n*=2;
        }
        y=n-tonner;
        cout<<g<<"*"<<a<<"/"<<t<<"+"<<d<<"="<<x<<"+"<<y<<endl;
       }
}
