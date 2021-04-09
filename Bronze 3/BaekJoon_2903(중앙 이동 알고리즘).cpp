#include<iostream>
#include<cmath>
using namespace std;
int square(int n)
{
    if(n==0)
        return 2;
    else
        return 2*square(n-1)-1;

}
int main()
{
    int N;
    int a;
    cin>>N;
    a=square(N);
    cout<<pow(a,2)<<endl;
}
//pow 반환형은 Double이예요
