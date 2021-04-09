#include<iostream>
using namespace std;
int main()
{
    int k,a,d;
    cin>>a>>d>>k;
    if((k-a)%d!=0 || ((k-a)/d)<0)
        cout<<"X"<<endl;
    else
        cout<<((k-a)/d+1)<<endl;
}
