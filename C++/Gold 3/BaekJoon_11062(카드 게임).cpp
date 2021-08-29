#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int T,N;
int card[1001];
int dp[1001][1001][2];

int Game(int st, int en, int turn){ // 0은 근우턴
    int &ref = dp[st][en][turn];
    
    if(st == en){
        if(turn == 0) return card[st];
        return 0;
    }
    
    if(ref != -1) return ref;
    
    if(turn == 0) ref = max(Game(st+1, en, 1) + card[st], Game(st, en-1, 1) + card[en]);
    else ref = min(Game(st + 1, en, 0), Game(st, en-1, 0)); // 명우 입장에서는 근우의 값이 최소값이 되는게 최상의 선택
    
    return ref;
}

void Input(){
    cin>>N;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i<N; i++) cin>>card[i];
}

int main(){
    FAST;
    cin>>T;
    while(T--){
        Input();
        cout<<Game(0, N-1, 0)<<endl;;
    }
}
