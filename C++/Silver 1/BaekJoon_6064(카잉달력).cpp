#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int T,N,M,x,y;

int GCD(int a, int b){
    if(b == 0) return a;
    return GCD(b,a%b);
}

void Solve(){
    int last = (N*M) / GCD(max(N ,M), min(M,N));
    if(y == N) y = 0;
    
    for(int i = x; i<=last; i+=M){
        if(i % N == y){
            cout<<i<<endl;
            return;
        }
    }
    cout<<"-1"<<endl;
}

int main(){
    FAST;
    cin>>T;
    while(T--){
        cin>>M>>N>>x>>y;
        Solve();
    }
}
