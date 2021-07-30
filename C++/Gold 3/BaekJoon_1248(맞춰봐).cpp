#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
char S[11][11];
int A[11];
int A_Sign[11];
int N;
bool ans;

bool Check(int now){
    for(int i = 0; i<now; i++){
        int comp = A[now] - A[i];
        if(comp > 0 && S[i+1][now] == '+') continue;
        if(comp < 0 && S[i+1][now] == '-') continue;
        if(comp == 0 && S[i+1][now] == '0') continue;
        return false;
    }
    return true;
}

void Print(){
    for(int i = 1; i<=N; i++){
        cout<<A[i] - A[i-1]<<' ';
    }
    cout<<'\n';
}

void Find_Ans(int now){
    if(ans) return;
    
    if(now == N + 1){
        ans = true;
        Print();
        return;
    }
    
    for(int i = 0; i<=10; i++){
        int num = i * A_Sign[now];
        A[now] = num + A[now-1];
        bool res = Check(now);
        if(res) Find_Ans(now+1);
    }
}

int main(){
    FAST;
    cin>>N;
    for(int i = 1; i<=N; i++){
        for(int j = i; j <= N; j++){
            cin>>S[i][j];
            if(i == j){
                if(S[i][j] == '-') A_Sign[i] = -1;
                else if(S[i][j] == '+')A_Sign[i] = 1;
                else A_Sign[i] = 0;
            }
        }
    }
    Find_Ans(1);
}
