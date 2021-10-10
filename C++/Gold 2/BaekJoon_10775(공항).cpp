#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int isDocking[100001];
int plainGate[100001];
int G,P,ans;
// 그리디 문제야 어떻게 그리디 할꺼야? 만약에 정렬할수만 있다면 4 2 2 2 1 이 있어 그러면

int getGate(int x){
    if(isDocking[x] == x) return x;
    return isDocking[x] = getGate(isDocking[x]);
}

bool Union(int x){
    int par_x = getGate(x);
    
    if(par_x == 0) return false;
    
    isDocking[par_x] = par_x -1;
    
    return true;
}

void Solve(){
    for(int i = 0; i<100001; i++) isDocking[i] = i;
    
    for(int i = 0; i<P; i++){
        int gateNum = plainGate[i];
        if(!Union(gateNum)) return;
        ans++;
    }
}

int main(){
    FAST;
    cin>>G>>P;
    for(int i = 0; i<P; i++) cin>>plainGate[i];
    Solve();
    cout<<ans<<endl;
}
