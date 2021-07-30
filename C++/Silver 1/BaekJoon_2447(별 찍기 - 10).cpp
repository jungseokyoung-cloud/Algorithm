#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
void Show_star(int x,int y,int n)
{
    FAST;
    if((x/n)%3==1 && (y/n)%3==1)
        cout<<' ';
    else
    {
        if(n==1)
            cout<<'*';
        else
            return Show_star(x, y, n/3);
    }
    
}
int main()
{
    FAST;
    int N;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        Show_star(i, j, N);
        cout<<'\n';
    }
}
