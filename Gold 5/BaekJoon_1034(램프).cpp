#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
char board[51][51];
int N,M,K,Max;
int zero[51];
int Change_Board(int x){
//    cout<<x<<endl;
    int sum=0;
    for(int i=0; i<N; i++)
    {
        bool ans=true;
        for(int j=0; j<M; j++)
        {
            if(board[i][j]!=board[x][j]){
                ans=false;
                break;
            }
        }
        if(ans) sum++;
    }
    return sum;
}
void Solve(){
    for(int i=0; i<N; i++){
        if(zero[i]>K || zero[i]%2!=K%2) continue;
        Max=max(Max, Change_Board(i));
    }
}
int main(){
    FAST;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++)
        {
            cin>>board[i][j];
            if(board[i][j]=='0')
                zero[i]++;
        }
    }
    cin>>K;
    Solve();
    cout<<Max<<'\n';
}
