#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N;
int arr [100000];
vector<int> ans;

void input() {
    ans.clear();
    for(int i = 0; i<N; i++) cin>>arr[i];
}

int findIdx(int target){
    int st = 0;
    int en = (int)ans.size()-1;
    
    while(st < en){
        int mid = (st + en)/2;
        
        if(ans[mid] < target) st = mid + 1;
        else en = mid;
    }
    return en;
}

void solve() {
    ans.push_back(arr[0]);
    for(int i = 1; i<N; i++){
        if(ans.back() < arr[i]) ans.push_back(arr[i]);
        else {
            int idx = findIdx(arr[i]);
            ans[idx] = arr[i];
        }
    }
}

int main(){
    FAST;
    while(cin>>N){
        input();
        solve();
        cout<<ans.size()<<endl;
    }
}
