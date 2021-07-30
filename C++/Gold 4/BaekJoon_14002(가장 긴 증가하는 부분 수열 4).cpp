#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int arr[1000];
int N;
pair<int, int> ans[1000];
vector<int> res;

void MakeAns(int idx){
    if(ans[idx].second == idx){
        res.push_back(arr[idx]);
        return;
    }
    MakeAns(ans[idx].second);
    res.push_back(arr[idx]);
}

void Solve(){
    
    ans[0].first = 1;
    int ansIdx = 0;
    int ansSize = 1;
    for(int i = 1; i<N; i++){
        ans[i].first = 1;
        ans[i].second = i;
        for(int j = 0; j<i; j++){
            if(arr[i] <= arr[j]) continue;
            if(ans[i].first < ans[j].first+1){
                ans[i].first = ans[j].first + 1;
                ans[i].second = j;
            }
        }
        if(ansSize < ans[i].first){
            ansSize = ans[i].first;
            ansIdx = i;
        }
    }
    MakeAns(ansIdx);
}

int main(){
    FAST;
    cin>>N;
    for(int i = 0; i<N; i++) cin>>arr[i];
    Solve();
    cout<<res.size()<<'\n';
    for(auto  r : res) cout<<r<<' ';
    cout<<'\n';
}
