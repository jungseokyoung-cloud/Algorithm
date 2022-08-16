#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N;
int arr[101];
vector<int> ans;

int gcd(int a, int b) {
    if(a % b == 0) return b;
    return gcd(b, a%b);
}

void init() {
    cin>>N;
    for(int i = 0; i<N; i++) cin >> arr[i];
    sort(arr, arr + N);
}

void solve() {
    int step = arr[1] - arr[0];
    
    for(int i = 2; i < N; i++){
        step = gcd(step, arr[i] - arr[i-1]);
    }
    for(int i = 1; i*i <= step; i++){
        if(step % i == 0) {
            
            ans.push_back(i);
            if(i != step / i) ans.push_back(step/i);
        }
    }
    sort(ans.begin(), ans.end());
}

int main(){
    FAST;
    init();
    solve();
    for(auto res : ans) {
        if(res == 1) continue;
        cout<<res<<' ';
    }
    cout<<endl;
}
