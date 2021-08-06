#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int board[4][4];
int N,M, ans;

void Solve(){
    for(int temp = 0; temp < (1<<(N*M)); temp ++){ // 배열을 일렬로 생각하여 해당 칸이 세로로 잘리면 1 아니면 0
        int comp = 0;                            // 경우의 수는 2^모든칸(모든칸을 0 아니면 1로 표현하기 때문).  현재 idx를 일렬도 표현
        
        for(int i = 0; i<N; i++){ // 가로 부분 체크
            int add = 0;
            
            for(int j = 0; j<M; j++){
                int k = i*M + j;
                
                if((temp & (1<<k)) == 0){ // k가 3번째 인덱스라면 00000100 이런식으로 될것이면 temp에서 0이라면 0이반환 temp에서 1이라면 1반환
                    add = add*10 + board[i][j];     // 따라서 해당 인덱스가 1인이 0인지
                }
                else {
                    comp += add;
                    add = 0;
                }
            }
            comp += add;
        }
        
        for(int i = 0; i<M; i++){
            int add = 0;
            
            for(int j = 0; j<N; j++){
                
                int k = j*M + i;
                if((temp & (1<<k)) != 0){
                    add = add*10 + board[j][i];
                }
                else {
                    comp += add;
                    add = 0;
                }
            }
            comp += add;
        }
        ans = max(ans, comp);
    }
}

int main(){
    FAST;
    cin>>N>>M;
    for(int i = 0; i<N; i++){
        char c;
        for(int j = 0; j<M; j++){
            cin>>c;
            board[i][j] = c - '0';
        }
    }
    Solve();
    cout<<ans<<endl;
}
