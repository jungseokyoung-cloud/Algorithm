#include<iostream>
using namespace std;

int main()
{
    int n;
    int cnt=0;
    cin>>n;
    int num;
    for(int nam=1; nam<n/2; nam++)
    {
        num=n;
        num=n-nam*2;
        for(int i=2; i<num; i++)
        {
            if((num-i)%2==0)
                cnt++;
        }
    }
    cout<<cnt<<endl;
}
