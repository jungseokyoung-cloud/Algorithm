#include<iostream>
using namespace std;

int main()
{
    int n;
    int cnt=0;
    int num;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>num;
        if((i+1)!=num)
            cnt++;
    }
    cout<<cnt<<endl;
}
