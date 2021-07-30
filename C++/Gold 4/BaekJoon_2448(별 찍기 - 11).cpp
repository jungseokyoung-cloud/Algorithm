#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
char arr[10000][10000];
void Make_Start(int x,int y,int n)
{
    if(n==3)
    {
        int middle=(2*y+5)/2;
        for(int i=x; i<x+3; i++)
        {
            for(int j=y; j<y+6; j++)
            {
                if((j-y)==2 && (i-x)==1) continue;
                else if(middle+(i-x)<j || middle-(i-x)>j) continue;
                else{ arr[i][j]='*';
                }
            }
        }
    }                           
    else
    {
        int bcol=((n/2)/3)*6;
        Make_Start(x,y+bcol/2,n/2); // 1번째 삼각형
        Make_Start(x+(n/2) , y, n/2);
        Make_Start(x+(n/2), y+n, n/2);
    }
}
int main()
{
    FAST;
    int N;
    cin>>N;
    Make_Start(0,0, N);
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<6*(N/3); j++)
        {
            if(arr[i][j]!='*')
                cout<<' ';
            else
                cout<<arr[i][j];
        }
        
        cout<<'\n';
    }
}
