#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define endl '\n'
int N, K;
ll ans;
int name[300000];
int res[21];

void Solve(){
    
    for(int i = 0; i<N; i++){
        if(i > K)   res[name[i - K -1]]--;
        ans += res[name[i]];
        res[name[i]] ++;
    }
}

int main(){
    FAST;
    cin>>N>>K;
    
    for(int i = 0; i<N; i++){
        string s;
        cin>>s;
        name[i] = s.size();
    }
    Solve();
    cout<<ans<<endl;
}
