//#include<bits/stdc++.h>
#include <iostream>
#include <limits.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 100001
int arr[MMAX];
int N,S,ans=INT_MAX;
void Solve(){
    int sum=0,start=0,end=0;
    while(start<=end && end<=N){
//        cout<<start<<' '<<end<<' '<<sum<<endl;
        if(sum>=S){
            ans=min(ans, end-start);
            sum-=arr[start++];
        }
        
        else if(sum<S) sum+=arr[end++];
    }
}
int main(){
    FAST;
    cin>>N>>S;
    for(int i=0; i<N; i++)
    cin>>arr[i];
        Solve();
    if(ans==INT_MAX) cout<<"0"<<'\n';
    else cout<<ans<<'\n';
}
