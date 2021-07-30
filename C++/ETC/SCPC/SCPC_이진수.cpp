#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 50001
int T,K,N;
string B;
int A[MMAX];

void Setting(){
    memset(A, -1, sizeof(A));
}

void Solve(){
    
    for(int i = 0; i<N; i++){
        int left = i - K;
        int right = i + K;
        if(B[i] == '0'){
            if(left >= 0){
                A[left] = 0;
            }
            if(right < N){
                A[right] = 0;
            }
        }
    }
    for(int i = 0; i<N; i++){
        int left = i - K;
        int right = i + K;
        if(B[i] == '0') continue;
        if(left >= 0 && right < N){
            if(A[right] == 0) A[left] = 1;
            else if(A[left] == 0) A[right] = 1;
            else if(A[left] == 1) continue;
            else if(A[right] != 0 && A[left] != 1)A[right] = 1;
        }
        else if(left < 0) A[right] = 1;
        else if(right >= N) A[left] = 1;
    }
}
    

int main(){
    FAST;
    cin>>T;
    for(int t = 1; t<=T; t++){
        cin>>N>>K;
        Setting();
        cin>>B;
        
        Solve();
        cout<<"Case #"<<t<<'\n';
        for(int i = 0; i<N; i++){
            if(A[i] == -1) cout<<'0';
            else    cout<<A[i];
        }
        cout<<'\n';
    }
}

