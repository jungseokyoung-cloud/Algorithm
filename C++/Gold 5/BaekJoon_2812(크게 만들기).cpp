#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N,K;
string s;
vector<char> ans;

void Solve(){
    for(int i = 0; i<N; i++){
        while(!ans.empty()){
            if(K == 0 || s[i] <= ans.back()) break;
            ans.pop_back();
            K--;
        }
        ans.push_back(s[i]);
    }
    while(K>0){
        ans.pop_back();
        K--;
    }
}

int main(){
    FAST;
    cin>>N>>K;
    cin>>s;
    Solve();
   
    for(auto res : ans) cout<<res;
    cout<<endl;
}
