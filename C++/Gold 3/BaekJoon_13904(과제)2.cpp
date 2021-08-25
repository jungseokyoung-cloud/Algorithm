#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int ans[10001];
pair<int, int> assign[10001];
int N,res;

bool comp(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

void FindNextidx(int deadline, int value){
    for(int i = deadline; i>=1; i--){
        if(ans[i] != 0) continue;
        ans[i] = value;
        res += value;
        return;
    }
}

void Solve(){
    sort(assign, assign+N, comp);
    
    for(int i = 0; i<N; i++){
        int deadline = assign[i].first;
        int value = assign[i].second;
        FindNextidx(deadline, value);
    }
}

int main(){
    FAST;
    cin>>N;
    for(int i = 0; i<N; i++) cin>>assign[i].first>>assign[i].second;
    Solve();
    cout<<res<<endl;
}
