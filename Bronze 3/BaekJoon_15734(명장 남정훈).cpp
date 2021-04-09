#include<iostream>
using namespace std;

int main()
{
    int l,r,a;
    int result;
    cin>>l>>r>>a;
    for(int i=0;i<a; i++)
    {
        if(l>r)
            r++;
        else
            l++;
    }
    result=l+r;
    if(l>r)
        result=l+r-(l-r);
    if(l<r)
        result=l+r-(r-l);
    cout<<result<<endl;
}
 
