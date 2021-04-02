#include <iostream>
#include<string>
using namespace std;
int main()
{
    string code;
    getline(cin,code);
    for(int i=0; i<code.size(); i++)
    {
        if(code[i]>='A' && code[i]<='Z')
        {
            code[i]+=13;
            if(code[i]>90)
                code[i]-=26;
        }
       if(code[i]>='a' && code[i]<='z')
        {
            if((code[i]+13)>122)
                code[i]-=13;
            else
                code[i]+=13;
        }
    }
    cout<<code<<endl;
}
