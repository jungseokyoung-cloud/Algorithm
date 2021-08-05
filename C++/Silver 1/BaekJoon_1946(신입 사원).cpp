#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N,T,ans;
pair<int, int> arr[100000];

bool comp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

void Solve(){
    sort(arr, arr + N, comp);
    ans = 1;
    int temp = arr[0].second;
    for(int i = 1; i<N; i++){
        if(arr[i].second > temp) continue;
        temp = arr[i].second;
        ans ++;
    }
}

int main(){
    FAST;
    cin>>T;
    while(T--){
        cin>>N;
        for(int i = 0; i<N; i++) cin>>arr[i].first>>arr[i].second;
        Solve();
        cout<<ans<<endl;
    }
}
