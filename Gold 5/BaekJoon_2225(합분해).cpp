#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define divid 1000000000
#define ll long long
ll arr[201][201];
int main()
{
    FAST;
    int N,K;
    cin>>N>>K;
    for(int i=1; i<=N; i++)
    arr[1][i]=1;
    for(int i=2; i<=K; i++)
    {
        for(int j=1; j<=N; j++)
        {
            for(int p=1; p<=j; p++)
            {
                arr[i][j]+=(arr[i-1][p]%divid);
            }
            arr[i][j]+=1;
        }
    }
    cout<<arr[K][N]%divid<<'\n';
}
