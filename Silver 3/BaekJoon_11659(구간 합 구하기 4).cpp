#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,M;
int arr[100001];

int main(){
    FAST;
    cin>>N>>M;
    for(int i = 1; i<=N; i++){
        cin>>arr[i];
        arr[i] += arr[i-1];
    }
    
    int a, b;
    while(M--){
        cin>>a>>b;
        cout<<arr[b] - arr[a-1]<<'\n';
    }
}
