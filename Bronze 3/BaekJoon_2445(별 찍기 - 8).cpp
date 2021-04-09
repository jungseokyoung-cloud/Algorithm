#include<iostream>
using namespace std;

int main()
{
    int n;
    int s;
    cin>>n;
    for(int i=1; i<2*n;i++)
    {
        if(i>n)
            s=2*n-i;
        else
            s=i;
            
        int cnt=0;
        for(int j=0; j<s; j++)
        {
            cout<<"*";
            cnt++;
        }
        for(int k=0; k<2*n-2*cnt; k++)
        cout<<' ';
        for(int j=0; j<s; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}
