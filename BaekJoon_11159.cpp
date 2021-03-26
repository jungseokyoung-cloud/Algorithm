#include<iostream>
using namespace std;

int main()
{
    int number;
    int n;
    int flag=0;
    int cnt=0;
        cin>>number;
        char *firstname = new char[number];
        for(int i=0;i<number;i++)
        {
            string name;
            cin>>name;
            firstname[i] = name[0];
        }
        for(char i='a'; i<='z'; i++)
        {
            cnt=0;
            for(int j=0; j<number; j++)
            {
                n=firstname[j]-i;
                if(n==0)
                {
                    cnt++;
                }
            }
            if(cnt>=5)
            {
                cout<<i; wag++;
            }
        }
    if(flag==0)
        cout<<"PREDAJA";
    
}
