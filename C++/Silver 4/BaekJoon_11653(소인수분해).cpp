#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N;
vector<int> ans;

void Solve(){
    for(int i = 2; i*i<=N; i++){
        while(N % i == 0){
            ans.push_back(i);
            N /= i;
        }
    }
    if(N != 1) ans.push_back(N);
}

int main(){
    FAST;
    cin>>N;
    Solve();
    for(auto a : ans) cout<<a<<endl;
}
