#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
bool isprime[1001];
int N;

void FindPrime(){
    isprime[1] = true;
    for(int i = 2; i<=1000; i++){
        if(isprime[i]) continue;
        for(int j = 2; j*i <=1000; j++){
            isprime[i*j] = true;
        }
    }
}

int main(){
    FAST;
    FindPrime();
    
    int cnt = 0;
    cin>>N;
    int num;
    for(int i = 0; i<N; i++){
        cin>>num;
        if(!isprime[num]) cnt++;
    }
    cout<<cnt<<endl;
}
