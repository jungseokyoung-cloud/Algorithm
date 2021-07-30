#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int MMAX = 10000;
int wine[MMAX];
int ans[MMAX];
int N,res;

void Solve(){
    ans[0] = wine[0];
    ans[1] = wine[0] + wine[1];
    ans[2] = max(wine[0] + wine[2], wine[1] + wine[2]);
    ans[2] = max(ans[2], ans[1]);
    res = ans[2];
    for(int i = 3; i<N; i++){
        ans[i] = max(ans[i-2] + wine[i], ans[i-3] + wine[i-1] + wine[i]); // i를 선택하는 경우의 수
        ans[i] = max(ans[i], ans[i-1]); // i 를 선택하지 않는 경우의 수
        res = max(ans[i], res);
    }
}

int main(){
    FAST;
    cin>>N;
    for(int i = 0; i<N; i++) cin >> wine[i];
    Solve();
    cout<<res<<'\n';
}
