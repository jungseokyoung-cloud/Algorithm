#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
bool isprime[1000001];
int N,M;

void FindPrime(){
    isprime[1] = true;
    for(int i = 2; i*i<1000001; i++){
        if(isprime[i]) continue;
        for(int j = 2; j*i <1000001; j++){
            isprime[i*j] = true;
        }
    }
}


int main(){
    FAST;
    FindPrime();
    cin>>N>>M;
    for(int i = N; i<=M; i++){
        if(isprime[i]) continue;
        cout<<i<<endl;
    }
}
