#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int GCD(int big, int small)
{
    FAST;
    if(big%small==0)
        return small;
    else
        return GCD(small,big%small);
}

int main()
{
    int n1,n2;
    cin>>n1>>n2;
    int gcd=GCD(n1, n2);
    int LCM=(n1*n2)/gcd;
    cout<<gcd<<'\n'<<LCM<<'\n';
}
