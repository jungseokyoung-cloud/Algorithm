#include<iostream>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main()
{
    int i=0;
    while(1)
    {
        FAST;
        i++;
        int l,p,v;
        int result=0;
        cin>>l>>p>>v;
        if(l==0 && p==0 && v==0)
            break;
            result=(v/p)*l;
            if(v%p>=l && v%p!=0)
                result+=l;
            else if(v%p<l && v%p!=0)
                result+=(v%p);
        cout<<"Case "<<i<<": "<<result<<'\n';
    }
}
