#include <iostream>
using namespace std;
int main()
{
    int e,f,c;
    cin>>e>>f>>c;
    int drink=0;
    int remain=e+f;
    int result=0;
    while(1)
    {
        if(remain<c)
            break;
        else
        {
            drink=remain/c;
            remain=drink+remain%c;
            result+=drink;
        }
    }
    cout<<result<<endl;
}
