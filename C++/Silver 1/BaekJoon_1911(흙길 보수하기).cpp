#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N,L,ans;
pair<int, int> arr[10001];

bool comp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int Change(int & now, int len){
    int add = 0;
    add = len/L;
    now += add*L;
    if(len%L != 0){
        add += 1;
        now += L ;
    }
    return add;
}

void Solve(){
    sort(arr, arr+N, comp);
 
    int now = 0; // 어디서부터 판자를 깔아햐 하는지 !
    for(int i = 0; i<N; i++){
        int st = arr[i].first;
        int en = arr[i].second;
        
        if(now <= st){
            int len = en - st;
            now = st;
            ans += Change(now, len);
        }
        else{
            int len = en - now; // 덮어야 할 곳의 길이
            if(len <= 0) continue;
            ans += Change(now, len);
        }
    }
}


int main(){
    FAST;
    cin>>N>>L;
    for(int i = 0; i<N; i++) cin>>arr[i].first>>arr[i].second;
    Solve();
    cout<<ans<<endl;
}
