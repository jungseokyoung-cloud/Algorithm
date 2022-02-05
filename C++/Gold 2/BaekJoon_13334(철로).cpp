#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int N,D, ans;
pair<int, int> arr[100001];

bool comp (pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

void input() {
    cin>>N;
    for(int i = 0; i<N; i++){
        int a,b;
        cin>>a>>b;
        if(b < a) swap(a, b);
        arr[i] = {a,b};
    }
    cin>>D;
}

void solve(){
    sort(arr, arr + N, comp);
    priority_queue<int> pq;
   
    for(int i = 0; i<N; i++){
        int st = arr[i].first;
        int en = arr[i].second;

        if(en - st <= D)    pq.push(-st);

        while(!pq.empty()){
            int nowSt = -pq.top();
            
            if(nowSt < en - D) pq.pop();
            else {
                ans = max(ans, (int)pq.size());
                break;
            }
        }
    }
}

int main(){
    FAST;
    input();
    solve();
    cout<<ans<<endl;
}
