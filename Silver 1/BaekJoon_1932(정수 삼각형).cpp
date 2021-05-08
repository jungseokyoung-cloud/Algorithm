#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 501
int arr[MMAX][MMAX];
int ans[MMAX][MMAX];
int main()
{
    int Max=0,N;
    FAST;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<=i; j++)
            cin>>arr[i][j];
    }
    ans[0][0]=arr[0][0];
    for(int i=1; i<N; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(j>0 && j<i)
            {
                ans[i][j]=max(ans[i-1][j], ans[i-1][j-1])+arr[i][j];
                
            }
            else if(j==0)
                ans[i][j]=ans[i-1][j]+arr[i][j];
            else if(j==i)
            {
                ans[i][j]=ans[i-1][j-1]+arr[i][j];
            }
            if(Max<ans[i][j])
                Max=ans[i][j];
        }
    }
    cout<<Max<<'\n';
}
