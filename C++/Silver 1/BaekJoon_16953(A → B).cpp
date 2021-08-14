#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long
const int MMAX = 1000000000;
int st,en,ans = -1;

ll Cal(ll num, int i){
    if(i == 0) return num*2;
    else    return num*10 + 1;
}

void BFS(){
    queue<pair<ll, int>> pos;
    pos.push({st,1});
    
    while(!pos.empty()){
        ll now = pos.front().first;
        int cnt = pos.front().second;
        pos.pop();
        if(now == en){
            ans = cnt;
            return;
        }
        for(int i = 0; i<2; i++){
            ll next = Cal(now, i);
            if(next > MMAX) continue;
            pos.push({next, cnt + 1});
        }
    }
}

int main(){
    FAST;
    cin>>st>>en;
    BFS();
    cout<<ans<<endl;
}
