#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N,ans = 1;
pair<int, int> lecture[200000];

bool comp(pair<int, int>a, pair<int, int>b){
    if(a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}

void Solve(){
    sort(lecture, lecture+N, comp);
    
    priority_queue<int> lec;
    lec.push(-lecture[0].second);
    
    for(int i = 1; i<N; i++){
        int lastLec = -lec.top();
        if(lecture[i].first >= lastLec){
            lec.pop();
            lec.push(-lecture[i].second);
        }
        else {
            lec.push(-lecture[i].second);
            ans++;
        }
    }
}

int main(){
    FAST;
    cin>>N;
    for(int i = 0; i<N; i++){
        cin>>lecture[i].first>>lecture[i].second;
    }
    Solve();
    cout<<ans<<endl;
}
