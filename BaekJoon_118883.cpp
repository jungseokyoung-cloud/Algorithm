#include<iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int num=1;
    for(int i=0; i<n; i++)
    {
        cout<<num;
        num++;
        for(int j=0; j<m-1; j++)
        {
            cout<<' '<<num;
            num++;
        }
            cout<<endl;
    }
    cout<<endl;
}
