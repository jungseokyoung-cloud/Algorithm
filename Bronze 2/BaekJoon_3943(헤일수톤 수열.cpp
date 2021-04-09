#include<iostream>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int maxnum;
int maxNum(int num)
{
    if(maxnum<=num)
        maxnum=num;
    if(num==1)
        return maxnum;
    else
        return num%2? maxNum(3*num+1) : maxNum(num/2);
}
int main()
{
    FAST;
    int t;
    cin>>t;
    int n;
    for(int i=0; i<t; i++)
    {
        cin>>n;
        maxnum=n;
        cout<<maxNum(n)<<'\n';
    }
}
