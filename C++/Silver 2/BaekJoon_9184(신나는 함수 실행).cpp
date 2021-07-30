#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int ans[21][21][21];
int w(int a,int b, int c)
{
    if(a<=0 || b<=0 || c<=0)
        return 1;
    
    else if(a>20 || b>20 || c>20)
        return w(20, 20, 20);
    else if(ans[a][b][c]!=0)
        return ans[a][b][c];
    else if(a<b && b<c)
       ans[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    else
       ans[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
    return ans[a][b][c];
}
int main()
{
    FAST;
    int a,b,c;
    int ans;
    while(1)
    {
        cin>>a>>b>>c;
        if(a==-1 && b==-1 && c==-1)
            break;
        ans=w(a, b, c);
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<ans<<'\n';
    }
}
