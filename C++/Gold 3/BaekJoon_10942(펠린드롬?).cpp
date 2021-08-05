#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int isPalin[2001][2001];
int palin[2001];
int N,M;

int DFS(int st, int en){
    int &ref = isPalin[st][en];
    
    if(ref != -1) return ref;
    if(st >= en) return ref = 1;
    
    
    if(palin[st] == palin[en])  ref = DFS(st+1, en-1);
    else ref = 0;
    return ref;
}

int main(){
    FAST;
    memset(isPalin, -1, sizeof(isPalin));
    cin>>N;
    for(int i = 1; i<=N; i++) cin>>palin[i];
    cin>>M;
    for(int i = 0; i<M; i++){
        int s,e;
        cin>>s>>e;
        cout<<DFS(s, e)<<endl;
    }
}
