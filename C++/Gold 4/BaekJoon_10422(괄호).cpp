#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
const ll divide = 1000000007;
int T,L;
ll ans[5001];
void Solve(){
    ans[0] = 1;
    for(int i = 2; i<=5000; i+=2){
        for (int j=0; j<=i-2; j+=2) {
            ans[i] += ans[j]*ans[i-2-j];
            ans[i] %= divide;
        }
    }
}

int main(){
    FAST;
    cin>>T;
    Solve();
    while(T--){
        cin>>L;
        cout<<ans[L]<<'\n';
    }
}
