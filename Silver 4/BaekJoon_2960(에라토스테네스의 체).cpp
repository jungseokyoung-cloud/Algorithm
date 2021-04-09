#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    FAST;
    int n,k,result;
    cin>>n>>k;
    bool answer[1005];
    memset(answer, true, sizeof(answer));
    for(int i=2; i<=n; i++)
    {
        if(answer[i])
        {
            for(int j=1; (j*i)<=n; j++)
            {
                 if(answer[i*j])
                {
                    k--;
                    answer[i*j]=false;
                    if(k==0)
                        result=i*j;
                }
            }
        }
    }
    cout<<result<<'\n';
}
