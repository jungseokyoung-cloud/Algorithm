#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N;
int board[17][17];
int cost[17][1 << 16];
int ans = INT_MAX;

void init() {
    cin>>N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++) cin>>board[i][j];
    }
    memset(cost, -1, sizeof(cost));
}

int solve(int now, int status) {
    if(status == (1 << N) -1) {
//        cout<<now<<"-----"<<endl;
//        cout<<board[now][0]<<endl;
        if(board[now][0] == 0) return INT_MAX;
        return board[now][0];
    }
    int &ref = cost[now][status];
    if(ref != -1) return ref;
    ref = INT_MAX;
    
    for(int i = 0; i<N; i++){
        if(board[now][i] == 0) continue;
        if((status & (1 << i)) == (1 << i)) continue;
        int temp = solve(i, status | 1 << i);
        if(temp == INT_MAX) continue;
//        cout<<temp<<endl;
//        cout<<ref<<' '<<temp<<' '<<cost[now][i]<<endl;
        ref = min(ref, temp + board[now][i]);
    }
    
    return ref;
}

int main(){
    FAST;
    init();
    cout<<solve(0, 1)<<endl;
}
