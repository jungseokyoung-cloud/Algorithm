#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long
const int divide = 1000000007;
int N;
ll dp[100001];
ll fact;
void Solve(){
    dp[2] = 1;
    fact = 2;

    for(int i = 3; i<=N; i++){
        dp[i] = (dp[i-1] + dp[i-2])*(i-1)%divide;
        fact = (fact*i)%divide;
        
    }
}
int main(){
    FAST;
    cin>>N;
    Solve();
    cout<<dp[N]*fact%divide<<endl;
}
