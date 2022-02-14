#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long
int N,M,ans;
int arr[10001];

void input(){
    cin>>N>>M;
    for(int i = 0; i<M; i++) cin>>arr[i];
}

ll getTime() {
    ll st = 0;
    ll en = 2000000000LL*30LL;
    
    while(st < en){
        ll mid = (st + en)/2;
        ll child = M;
        
        for(int i = 0; i<M; i++) child += mid/arr[i];
        
        if(child < N) st = mid + 1;
        else en = mid;
    }
    return en;
}

void solve(){
    if(N <= M){
        ans = N;
        return;
    }
    
    ll time = getTime();
    ll child = M;
    
    for(int i = 0; i<M; i++) child += (time-1) / arr[i]; // time-1까지 탄애들 모두 구한다.!

    for(int i = 0; i<M; i++){
        if(time % arr[i] != 0) continue;

        if(++child == N){
            ans = i+1;
            return;
        }
    }
}

int main(){
    FAST;
    input();
    solve();
    cout<<ans<<endl;
}
