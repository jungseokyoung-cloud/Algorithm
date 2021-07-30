#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
ll N,K;

ll Find(ll value){
    ll res = 0;
    for(int i = 1; i<=N; i++){
        res +=  min(value/i, N);
    }
    return res;
}


ll BinarySearch(){
    ll start = 1;
    ll end = N*N;
    while(start < end){
        ll mid = (start + end)/2;
        if(Find(mid) < K) start = mid + 1;
        else end = mid;
    }
    return end;
}

int main(){
    FAST;
    cin>>N>>K;
    cout<<BinarySearch()<<'\n';
}
