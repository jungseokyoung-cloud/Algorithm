 #include<iostream>
#include<cmath>
using namespace std;

int main()
{
    double n;
    cin>>n;
    int num=(int)sqrt(n);
    int cnt=num-1;
    int result=(num-1)*4;
    if(n<=3)
        cout<<"4"<<endl;
    else
    {
    for(int i=num*num+1; i<=n; i++)
    {
        cnt++;
        if(cnt==num)
        {
            cnt=0;
            result+=2;
        }
    }
    cout<<result<<endl;
    }
}
