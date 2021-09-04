#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define endl '\n'
ll dp[31][31];

ll Solve(int w, int h){
    if(h < 0) return 0;
    if(w == 0) return 1;
    
    ll &ref = dp[w][h];
    
    if(ref != -1) return ref;
    ref = Solve(w-1, h+1) + Solve(w, h-1);
    
    return ref;
}

int main(){
    FAST;
    memset(dp, -1, sizeof(dp));
    while(1){
        int num;
        cin>>num;
        if(num == 0) break;
        cout<<Solve(num, 0)<<endl;
    }
}
