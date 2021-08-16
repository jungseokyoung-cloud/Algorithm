#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
struct product{
    int from,to,cost;
};

int N,C,M,ans;
int cnt[2001];
vector<product> arr;


bool comp(product a, product b){
    if(a.to == b.to) return a.from > b.from;
    return a.to < b.to;
}

int Check(int from, int to){
    int res = 0;
    for(int i = from; i<to; i++){
        res = max(cnt[i], res);
    }
    return res;
}

void MakeCnt(int from, int to, int value){
    for(int i = from; i<to; i++){
        cnt[i] += value;
    }
}

void Solve(){
    sort(arr.begin(), arr.end(), comp);
    
    for(int i = 0; i<arr.size(); i++){
        int value = C - Check(arr[i].from, arr[i].to); // 추가 할수 있는값
        if(value > arr[i].cost){
            value = arr[i].cost;
        }
        MakeCnt(arr[i].from, arr[i].to, value);
        ans += value;
    }
}

int main(){
    FAST;
    cin>>N>>C>>M;
    for(int i = 0; i<M; i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr.push_back({a,b,c});
    }
    
    Solve();
    cout<<ans<<endl;
}
