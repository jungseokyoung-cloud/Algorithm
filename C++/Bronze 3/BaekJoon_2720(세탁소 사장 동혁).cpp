#include <iostream>
using namespace std;

int main()
{
    int test;
    int rem;
    cin>>test;
    
    for(int i=0; i<test; i++)
    {
        int q=1,d=1,n=1,p=1;
        cin>>rem;
        while(1)
        {
            if(q*25>rem)
            {
                q=q-1;
                break;
            }
            q++;
        }
        rem-=25*q;
        while(1)
        {
            if(d*10>rem)
            {
                d=d-1;
                break;
            }
            d++;
        }
        rem-=10*d;
        while(1)
        {
            if(n*5>rem)
            {
                n=n-1;
                break;
            }
            n++;
        }
        p=rem-5*n;
        cout<<q<<' '<<d<<' '<<n<<' '<<p<<endl;
    }
}
