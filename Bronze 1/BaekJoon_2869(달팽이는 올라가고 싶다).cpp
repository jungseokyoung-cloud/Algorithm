#include<iostream>
using namespace std;

int main()
{
    int a,b,v;
    cin>>a>>b>>v;
    int day;
        if((v-a)%(a-b)!=0)
        day=(v-a)/(a-b)+2;
        else
            day=(v-a)/(a-b)+1;
    cout<<day<<endl;
}
