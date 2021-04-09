#include <iostream>
#include<string>
using namespace std;

int main()
{
    string s1;
    cin>>s1;
    for(int i=0; i<s1.size(); i++)
    {
        cout<<s1[i];
        if((i+1)%10==0)
            cout<<endl;
    }
}
