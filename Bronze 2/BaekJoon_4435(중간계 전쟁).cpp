#include<iostream>
using namespace std;

int main()
{
    int gun[6];
    int hobbit[7];
    int test;
    cin>>test;
    for(int i=0; i<test; i++)
    {
        int result=0, result2=0;
        for(int j=0; j<6; j++)
        cin>>gun[j];
        for(int j=0; j<7; j++)
        cin>>hobbit[j];
        result=gun[0]+2*gun[1]+3*gun[2]+3*gun[3]+4*gun[4]+ 10*gun[5];
        result2=hobbit[0]+2*hobbit[1]+2*hobbit[2]+2*hobbit[3]+3*hobbit[4]+ 5*hobbit[5]+10*hobbit[6];
        if(result>result2)
            cout<<"Battle "<<i+1<<": Good triumphs over Evil"<<endl;
        if(result<result2)
            cout<<"Battle "<<i+1<<": Evil eradicates all trace of Good"<<endl;
        if(result==result2)
            cout<<"Battle "<<i+1<<": No victor on this battle field"<<endl;
    }
}
