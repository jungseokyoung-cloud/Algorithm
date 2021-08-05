#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
const int divide = 10007;
int N,K;
int dp[1001][1001];

int DFS(int n, int k){
    int &ref = dp[n][k];
        
    if(ref != -1) return ref;
    if(k == 1) return ref = n;
    if(k == 0 || n == k) return ref = 1;
    
    ref = (DFS(n-1, k) + DFS(n-1, k-1)) % divide;
    
    return ref;
}

int main(){
    FAST;
    memset(dp, -1, sizeof(dp));
    cin>>N>>K;
    cout<<DFS(N , K)<<endl;
}
