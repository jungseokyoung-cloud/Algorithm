#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
const int MMAX = 10000001;
pair<int, int> ans[MMAX]; //first에는 양수 second에는 음수
int N,M;
int arr[500000];

int Find_idx(int target){
    int idx = upper_bound(arr, arr+N, target) - arr;
    int idx2 = lower_bound(arr, arr+N, target) - arr;
    return idx - idx2;
}

void Solve(){
    sort(arr, arr + N);
    int target = arr[0];
    if(arr[0] < 0) ans[abs(arr[0])].second = Find_idx(target);
    else ans[arr[0]].first = Find_idx(target);
    
    for(int i = 1; i<N; i++){
        if(target == arr[i]) continue;
        target = arr[i];
        if(arr[i] < 0) ans[-arr[i]].second = Find_idx(target);
        else ans[arr[i]].first = Find_idx(target);
    }
}

int main(){
    FAST;
    cin>>N;
    for(int i = 0; i<N; i++) cin>>arr[i];
    Solve();
    cin>>M;
    int num;
    while(M--){
        cin>>num;
        if(num < 0) cout<<ans[-num].second<<' ';
        else cout<<ans[num].first<<' ';
    }
    cout<<endl;
}
