#include <iostream>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main()
{
    FAST;
    int n;
    cin>>n;
    long long arr[80]={2,4};
    for(int i=2; i<n+1; i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    }
    cout<<arr[n]<<'\n';
}
