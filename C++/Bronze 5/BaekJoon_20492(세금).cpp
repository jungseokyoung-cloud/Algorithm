#include <iostream>
using namespace std;

int main()
{
    int n;
    int mon1,mon2;
    cin>>n;
    mon1=n*(1-0.22);
    mon2=n*(1-0.044);
    cout<<mon1<<' '<<mon2<<endl;
}
