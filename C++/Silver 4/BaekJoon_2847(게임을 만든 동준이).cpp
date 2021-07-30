#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int main()
{
    int n,ans=0;
    cin>>n;
    vector<int> v(n);
    for(int i=(n-1); i>-1; i--) //뒤에서부터 입력받음
    cin>>v[i];
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(v[i]<=v[j]) //뒤에 애들이 더 작아야함.
            {
                ans+=(v[j]-v[i]+1);
                v[j]=v[j]-(v[j]-v[i]+1);
            }
        }
    }
    cout<<ans<<'\n';
}
