#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 1000001
int vis[MMAX];
int Top,Start,Arrive,U,D;
int Move(int idx){
    if(idx==0) return U;
    else return -D;
}
void Solve(){
    vis[Start]=0;
    queue<int>pos;
    pos.push(Start);
    
    while(!pos.empty()){
        int x=pos.front();
        pos.pop();
        if(x==Arrive){
            cout<<vis[x]<<'\n';
            return;
        }
        for(int i=0; i<2; i++){
            int nx=x+Move(i);
            if(nx<1 || nx>Top) continue;
            if(vis[nx]>=0) continue;
            vis[nx]=vis[x]+1;
            pos.push(nx);
        }
    }
    cout<<"use the stairs"<<'\n';
}
int main(){
    FAST;
    fill(vis, vis+MMAX, -1);
    cin>>Top>>Start>>Arrive>>U>>D;
    Solve();
}
