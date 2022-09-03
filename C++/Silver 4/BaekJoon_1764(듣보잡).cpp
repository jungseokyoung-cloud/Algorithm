ㅌ2#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
string arr1[500000], arr2[500000];
int N, M;
vector<string> ans;

void init() {
    cin>>N>>M;
    
    for(int i = 0; i<N; i++){
        cin>>arr1[i];
    }
    for(int i = 0; i<M; i++){
        cin>>arr2[i];
    }
    sort(arr1, arr1+N);
    sort(arr2, arr2+M);
}

bool binary_search_(string target){
    int st = 0;
    int en = M-1;
    while(st <= en){
        int mid = (st + en)/2;
        if(arr2[mid] < target) st = mid + 1;
        else if(arr2[mid] > target) en = mid - 1;
        else return true;
    }
    return false;
}

void solve() {
    for(int i = 0; i<N; i++){
        if(binary_search_(arr1[i])) ans.push_back(arr1[i]);
    }
    sort(ans.begin(), ans.end());
}


int main() {
    FAST;
    init();
    solve();
    
    cout<<ans.size()<<endl;
    for(auto res : ans) cout<<res<<endl;
    
}
