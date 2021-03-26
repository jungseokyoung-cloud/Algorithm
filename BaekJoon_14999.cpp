#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a;
    string b;
    cin>>a;
    cin>>b;
    if(a.size()>=b.size())
        cout<<"go"<<endl;
    else
        cout<<"no"<<endl;
}
