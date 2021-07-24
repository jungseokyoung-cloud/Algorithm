#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int T,K;
int book[501];
int ans[501][501]; // i~j까지 합쳤을때

int DFS(int st, int en){
    
    int &ref = ans[st][en];
    
    if(ref != -1) return ref;
    
    if(st == en) return 0;
    
    if(en - st == 1) return ref = book[en] - book[st-1];
    
    ref = INT_MAX;
    
    for(int i = st; i<en; i++){
        ref = min(ref, DFS(st, i) + DFS(i+1, en) + book[en] - book[st-1]);
    }
    return ref;
}

int main(){
    FAST;
    cin>>T;
    while(T--){
        cin>>K;
        memset(ans, -1, sizeof(ans));
        for(int i = 1; i<=K; i++){
            cin>>book[i];
            book[i] += book[i-1];
        }
        cout<<DFS(1, K)<<'\n';
    }
}
