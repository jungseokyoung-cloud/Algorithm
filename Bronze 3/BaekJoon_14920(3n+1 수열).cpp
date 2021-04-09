#include<iostream>
using namespace std;

int main()
{
    int c1;
    cin>>c1;
    int cnt=1;
    while(1)
    {
        if(c1==1)
            break;
        else
        {
            if(c1%2==0)
                c1=c1/2;
            else
                c1=3*c1+1;
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
