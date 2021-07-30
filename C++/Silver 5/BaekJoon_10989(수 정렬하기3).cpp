#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main()
{
    int arr[10000]={0,};
    FAST;
    int n,N,max=0;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>n;
        if(max<n)
            max=n;
        arr[n-1]+=1;
    }
    for(int i=0; i<max; i++)
    {
        if(arr[i]==1)
            cout<<i+1<<'\n';
        else if(arr[i]>1)
        {
            for(int j=0; j<arr[i]; j++)
            {
                cout<<i+1<<'\n';
            }
        }
    }
}
