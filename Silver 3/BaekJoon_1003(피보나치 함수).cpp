#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int main()
{
    FAST;
    int T,n;
   pair<int, int>fibo[41]; //first 에는 0의 횟수가 secound에는 1의 횟수를 저장
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>n;
        memset(fibo, 0, sizeof(fibo));
        fibo[0].first=1;
        fibo[1].second=1;
        for(int j=2; j<=n; j++)
        {
            fibo[j].first=fibo[j-1].first+fibo[j-2].first;
            fibo[j].second=fibo[j-1].second+fibo[j-2].second;
        }
        cout<<fibo[n].first<<' '<<fibo[n].second<<'\n';
    }
}
