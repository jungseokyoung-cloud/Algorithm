#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N,ans;
int arr[1000];

bool Binary_Search(int target){
    int st = 0;
    int en = N-1;
    
    while(st <= en){
        int mid = (st + en)/2;
        if(arr[mid] < target) st = mid + 1;
        else if(arr[mid] > target) en = mid - 1;
        else return true;
    }
    return false;
}

void Solve(){
    sort(arr, arr + N);
    
    for(int k = N-1; k>=0; k--){
        for(int i = 0; i<=k; i++){
            for(int j = 0; j<=k; j++){
                int target = arr[k] - arr[i] - arr[j];
                if(target <= 0) continue;
                bool res = Binary_Search(target);
                if(res){
                    ans = arr[k];
                    return;
                }
            }
        }
    }
}

int main(){
    FAST;
    cin>>N;
    for(int i = 0; i<N; i++){
        cin>>arr[i];
    }
    Solve();
    cout<<ans<<endl;
}
