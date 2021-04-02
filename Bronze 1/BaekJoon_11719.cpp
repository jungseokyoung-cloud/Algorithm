#include<iostream>
using namespace std;
int main()
{
    int ch=10;
    while(1)
    {
        ch=getchar();
        if(ch==EOF)
            break;
        putchar(ch);
    }
}
