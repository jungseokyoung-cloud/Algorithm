#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
ll liquid[5000];
int N;
ll res = LLONG_MAX;
ll ans[3];

void Solve(){
    for(int i = 0 ; i < N-2; i++){
        int left = i+1;
        int right = N-1;
        while(left < right){
            ll comp = liquid[i] + liquid[left] + liquid[right];
            if(res > abs(comp)){
                res = abs(comp);
                ans[0] = liquid[i];
                ans[1] = liquid[left];
                ans[2] = liquid[right];
            }
            if(comp >= 0) right--;
            else left++;
        }
    }
}
int main(){
    FAST;
    cin>>N;
    for(int i=0; i<N; i++) cin>>liquid[i];
    sort(liquid, liquid+N);
    Solve();
    for(int i=0; i<3; i++) cout<<ans[i]<<' ';
    cout<<'\n';
}
