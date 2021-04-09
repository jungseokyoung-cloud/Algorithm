#include<iostream>
#include<cmath>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main()
{
    FAST;
    int a,t,fuck,result = 0,t2;
    cin>>a>>t>>fuck;
    t2=t;
    int index=2;
    int total=0;
    while(1)
    {
        total+=(index*2+4);
        if(t<=total/2)
            break;
        index++;
    }
    total-=(2*index+4);
    int x=(t-total/2)%(index+2);
    if(x==0)
        x=index+2;
    if(fuck==0)
    {
        if(x==1 ||x==2)
            result=t*2-1;
        else
            result=total+x+2;
    }
    else
    {
        if(x==1 ||x==2)
            result=t*2;
        else
            result=total+x+index+2;
    }
    cout<<(result-1)%a<<endl;
}
