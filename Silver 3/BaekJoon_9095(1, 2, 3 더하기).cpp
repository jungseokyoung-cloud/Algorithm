#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int main()
{
    FAST;
    int n,t;
    cin>>t;
    for(int j=0; j<t; j++)
    {
        int arr[12]{0,};
        arr[1]=1;
        arr[2]=2;
        arr[3]=4;
        cin>>n;
        for(int i=4; i<=n; i++)
        arr[i]=arr[i-1]+arr[i-2]+arr[i-3]; //i-1에서 1을 더하는 경우 i-2에서 2를 더하는 경우, i-3에서 3을 더하는 경우.
        cout<<arr[n]<<'\n';
    }

}
