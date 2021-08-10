#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
string s;
int cnt[2];
void Solve(){
    char comp = s[0];
    cnt[s[0] - '0']++;
    for(int i = 1; i<s.size(); i++){
        if(comp == s[i]) continue;
        comp = s[i];
        cnt[s[i] -'0'] ++;
    }
}

int main(){
    FAST;
    cin>>s;
    Solve();
    cout<<min(cnt[1],cnt[0])<<endl;
}
