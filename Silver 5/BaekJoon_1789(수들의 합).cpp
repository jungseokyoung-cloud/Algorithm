#include<iostream>
using namespace std;
int main()
{
    long long num,n=1,sum=0;
    cin>>num;
    while(1)
    {
//        if(sum>num)
//            break;
//        else
//            sum+=n;
//            n++;
        if(num<(n*(n+1)/2))
            break;
        n++;
    }
    cout<<n-1<<endl;
//    cout<<n-2<<endl;
}

