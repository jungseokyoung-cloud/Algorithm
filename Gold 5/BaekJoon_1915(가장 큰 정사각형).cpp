#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,M,res;
char arr[1001][1001];
int ans[1001][1001];

void Solve(){
    for(int i=0; i<N; i++)
    ans[i][0]=arr[i][0]-'0';
    for(int j=0; j<M; j++)
    ans[0][j]=arr[0][j]-'0';
    
    for(int i=1; i<N; i++)
    {
        for(int j=1; j<M; j++)
        {
            if(arr[i][j]=='0') continue;
            ans[i][j]=min(ans[i][j-1], ans[i-1][j]);
            ans[i][j]=min(ans[i][j], ans[i-1][j-1]);
            ans[i][j]+=1;
            res=max(res, ans[i][j]);
        }
    }
}
int main(){
    FAST;
    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='1')
                res=1;
        }
    }
    Solve();
    cout<<res*res<<'\n';
}
