#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N, ans;
pair<int, int> assign[1000];
int totalCost[1001];

bool comp(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

void InputData(int idx, int cost){
    while (idx > 0) {
        if(totalCost[idx] == 0) break;
        idx--;
    }
    if(idx == 0) return;
    totalCost[idx] = cost;
    ans += cost;
}

void Solve(){
    sort(assign, assign+N,comp);
    
    for(int i = 0; i<N; i++){
        int day = assign[i].first;
        int cost = assign[i].second;
        InputData(day, cost);
    }
}

int main(){
    FAST;
    cin>>N;
    for(int i = 0; i<N; i++){
        cin>>assign[i].first>>assign[i].second;
    }
    Solve();
    cout<<ans<<endl;
}
