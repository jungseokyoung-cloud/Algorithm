#include <iostream>
using namespace std;

int main()
{
    int num;
    int n;
    while(1)
    {
        cin>>num;
        if(num==0)
            break;
        else
        {
            int *inputnumber = new int[num];
            for(int i=0;i<num;i++)
            {
                cin>>n;
                inputnumber[i]=n;
                if(i==0)
                    cout<<inputnumber[i]<<' ';
                if(i>0 && inputnumber[i-1]!=inputnumber[i])
                    cout<<inputnumber[i]<<' ';
            }
            cout<<"$"<<endl;

        }
   
    }
}
