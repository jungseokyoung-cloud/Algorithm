#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N;
pair<int, int> arr[1000001];
int ans[1000001];

void Solve(){
    sort(arr, arr+N);
    
    int target = arr[0].first;
    int res = 0;
    
    for(int i = 1; i<N; i++){
        if(arr[i].first == target) ans[arr[i].second] = res;
        else {
            ans[arr[i].second] = ++res;
            target = arr[i].first;
        }
    }
}

int main(){
    FAST;
    cin>>N;
    for(int i = 0; i<N; i++){
        cin>>arr[i].first;
        arr[i].second = i;
    }
    Solve();
    for(int i = 0; i<N; i++) cout<<ans[i]<<' ';
    cout<<endl;
}
