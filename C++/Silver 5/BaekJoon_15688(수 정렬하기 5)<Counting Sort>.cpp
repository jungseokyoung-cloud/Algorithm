#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 1000000
int freq[MMAX+MMAX+1];
int N;
int main(){
    FAST;
    cin>>N;
    int a;
    for(int i=0; i<N; i++){
        cin>>a;
        freq[a+MMAX]++;
    }
    
    for(int i=0; i<=2*MMAX; i++){
        for(int j = 0; j<freq[i]; j++){
            cout<<i-MMAX<<'\n';
        }
    }
}
