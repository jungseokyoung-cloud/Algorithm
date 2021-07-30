#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,S,ans;
int arr[20];

void Find_S(int idx,int sum ,int cnt) // cnt가 0이면 공집합 1인 경우는 공집합 X
{
    if(sum==S && cnt>0)
        ans++;
    for(int i=idx; i<N; i++)
    {
        Find_S(i+1, sum+arr[i],1);
    }
}
void Find_S2(int idx, int sum)
{
    if(idx==N)
    {
        if(sum==S)
            ans++;
        return;
    }
    Find_S2(idx+1, sum);
    Find_S2(idx+1, sum+arr[idx]);
}
int main()
{
    FAST;
    cin>>N>>S;
    for(int i=0; i<N; i++)
    cin>>arr[i];
//    Find_S(0, 0, 0);
    Find_S2(0, 0);
    if(S==0)    ans-=1;
    cout<<ans<<'\n';
}
