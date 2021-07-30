#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,ans;
vector<pair<int, int>>arr;

void Solve(){
    sort(arr.begin(), arr.end());
    
    for(int i = 0; i<N; i++) ans = max(ans, arr[i].second - i);
}

int main(){
    FAST;
    cin>>N;
    for(int i = 0; i<N; i++){
        int num;
        cin>>num;
        arr.push_back({num,i});
    }
    Solve();
    
    cout<<ans+1<<'\n';
}
