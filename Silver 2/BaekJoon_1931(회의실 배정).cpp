#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
vector<pair<int, int>> confer;
int N;
int cnt,now;

bool comp(pair<int, int>a, pair<int, int> b){
    if(a.second == b.second)    return a.first < b.first;
    else   return a.second < b.second;
}

void Solve(){
    sort(confer.begin(), confer.end(), comp);
    
    for(int i = 0; i<N; i++){
        if(now > confer[i].first) continue;
        cnt++;
        now = confer[i].second;
    }
}

int main(){
    FAST;
    cin>>N;
    int Start, End;
    for(int i = 0 ; i<N; i++){
        cin>>Start>>End;
        confer.push_back({Start,End});
    }
    Solve();
    cout<<cnt<<'\n';
}
