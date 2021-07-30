#include <iostream>
using namespace std;

int main()
{
    int A,B,C;
    cin>>A>>B;
    cin>>C;
    int hour,min;
    hour=C/60+A;
    min=C%60+B;
    if(min>=60)
    {
        min=min-60;
        hour+=1;
    }
    hour%=24;
    cout<<hour<<' '<<min<<endl;
}
