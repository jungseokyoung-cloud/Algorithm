#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int weight[1000];
int N;
long long ans;

void Solve(){
    sort(weight, weight+N);
    if(weight[0] > 1) return;
    ans = 1;
    for(int i = 1; i<N; i++){
        if(ans + 1 < weight[i]) return;
        ans += weight[i];
    }
}

int main(){
    FAST;
    cin>>N;
    for(int i = 0; i<N; i++)  cin>>weight[i];
    Solve();
    cout<<ans+1<<endl;
}
