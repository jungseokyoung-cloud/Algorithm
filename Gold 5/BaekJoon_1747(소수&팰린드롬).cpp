#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 1004000
bool isPrime[MMAX];
int num,ans;
void Eratosthenes(){
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    for(int i=2; i<MMAX; i++){
        if(!isPrime[i]) continue;
        for(int j=2; j*i<MMAX; j++){
            isPrime[i*j] = false;
        }
    }
}

void Solve(){
    for(int i=num; i<MMAX; i++){
        if(!isPrime[i]) continue;
        string s1 = to_string(i);
        bool res = true;
        int end = s1.size()-1;
        for(int j=0; j<s1.size()/2; j++){
            if(s1[j] == s1[end-j]) continue;
            res = false;
            break;
        }
        if(res){
            ans = i;
            return;
        }
    }
}

int main(){
    FAST;
    Eratosthenes();
    cin>>num;
    Solve();
    cout<<ans<<'\n';
}
