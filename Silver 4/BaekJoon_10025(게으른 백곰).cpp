#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main()
{
    FAST;
    long long ice[1000001]={0,};
    int n,k,k2,h,x;
    long long cnt=0,ans=0;
    cin>>n>>k;
    for(int i=0; i<n; i++)
    {
        cin>>h>>x;
        ice[x]=h;
    }
    k=2*k+1;
    k2=k>1000001 ?1000001 : k ;
    for(int i=0; i<k2; i++) //0부터 2*k-1까지 ice의 합
        cnt+=ice[i];
           ans=cnt;
    for(int i=k2; i<1000001; i++)    //곰이 먹을수있는 범위값. 만약 한칸옆으로 간다면 그 전값을 빼주고 다음값을 더해줌 1000002
    {
        cnt-=ice[i-k];
        cnt+=ice[i];
        if(ans<cnt)
            ans=cnt;
    }
    cout<<ans<<'\n';
}
