#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N,M;
int isPalin[2001][2001];
int arr[2001];

int dp(int st, int en){
    if(st >= en) return 1;
    int &ref = isPalin[st][en];
    if(ref != -1) return ref;
    
    if(arr[st] == arr[en]) ref = dp(st+1, en-1);
    else ref = 0;
    
    return ref;
}

void Solve(){
    memset(isPalin, -1, sizeof(isPalin));
    cin>>M;
    int st,en;
    while(M--){
        cin>>st>>en;
        cout<<dp(st, en)<<endl;
    }
}

int main(){
    FAST;
    cin>>N;
    for(int i = 1; i<=N; i++) cin>>arr[i];
    Solve();
}
