#include <iostream>
#include <cstring>
#include<cstdlib>
using namespace std;

int main()
{
    char s1[100];
    int k,d,a;
    int cnt=0;
    cin>>s1;
    char *ptr = strtok(s1, "/");

    while(ptr != NULL)
    {
        if(cnt==0)
        {
            k=atoi(ptr);
            cnt++;
            ptr=strtok(NULL, "/");
        }
        if(cnt==1)
        {
            d=atoi(ptr);
            cnt++;
            ptr=strtok(NULL, "/");
        }
        if(cnt==2)
        {
            a=atoi(ptr);
            cnt++;
            ptr=strtok(NULL, "/");
        }
    }
    if((k+a)<d || d==0)
        cout<<"hasu"<<endl;
    else
        cout<<"gosu"<<endl;
}
//cin.getline()
