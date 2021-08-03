#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
string s;
int K,ans = -1;
bool vis[1000001][11];
bool res;


void Solve(){
    
    if(s.size() == 1 && (s.size() == 2 && s[1] == '0')) return;
    
    queue<pair<string, int>> q;
    q.push({s,0});
    
    while(!q.empty()){
        string now = q.front().first;
        int nowK = q.front().second;
        q.pop();
        if(nowK == K){
            ans = max(ans, stoi(now));
            continue;
        }
        
        for(int i = 0; i<now.size()-1; i++){
            for(int j = i + 1; j<now.size(); j++){
                string next = now;
                swap(next[i], next[j]);
                if(next[0] == '0' || vis[stoi(next)][nowK + 1]) continue;
                q.push({next, nowK + 1});
                vis[stoi(next)][nowK + 1] = true;
            }
        }
    }
}

int main(){
    FAST;
    cin>>s;
    cin>>K;
    Solve();
    cout<<ans<<endl;
}
