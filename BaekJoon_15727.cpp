#include <iostream>
using namespace std;

int main()
{
    int l;
    int time=0;
    cin>>l;
    
    while(1)
    {
        if(l==0)
            break;
        if(l<5)
        {
            time+=1;
            break;
        }
        else
        {
            l=l-5;
            time+=1;
        }
    }
    cout<<time<<endl;
}
