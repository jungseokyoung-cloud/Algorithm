#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
ll T,ans;
ll temp[1001];
vector<ll> A;
vector<ll> B;
int N,M;

void Input(){
    cin>>T;
    cin>>N;
    for(int i = 0; i<N; i++)   cin>>temp[i];
    
    for(int i = 0; i<N; i++){
        ll add = temp[i];
        A.push_back(add);
        for(int j = i+1; j<N; j++){
            add += temp[j];
            A.push_back(add);
        }
    }
    
    cin>>M;
    for(int i = 0; i<M; i++)    cin>>temp[i];
    
    for(int i = 0; i<M; i++){
        ll add = temp[i];
        B.push_back(add);
        for(int j = i+1; j<M; j++){
            add += temp[j];
            B.push_back(add);
        }
    }
}

void Solve(){
    sort(B.begin(), B.end());
    
    for(int i = 0; i<A.size(); i++){
        ll target = T - A[i];
        int idx1 = lower_bound(B.begin(), B.end(), target) - B.begin();
        int idx2 = upper_bound(B.begin(), B.end(), target) - B.begin();
        ans += (idx2 - idx1);
    }
}

int main(){
    FAST;
    Input();
    Solve();
    cout<<ans<<'\n';
}
