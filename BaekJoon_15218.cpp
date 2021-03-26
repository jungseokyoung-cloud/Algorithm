#include<iostream>
#include<string>
using namespace std;

int main()
{
    int test;
    int distance;
    string s1,s2;
    cin>>test;
    for(int i=0; i<test; i++)
    {
        cin>>s1>>s2;
        cout<<"Distances: ";
        for(int j=0; j<s1.size(); j++)
        {
            if(s1[j]<=s2[j])
                distance=s2[j]-s1[j];
            else
                distance=s2[j]+26-s1[j];
            cout<<distance<<' ';
        }
        cout<<endl;
    }
}
