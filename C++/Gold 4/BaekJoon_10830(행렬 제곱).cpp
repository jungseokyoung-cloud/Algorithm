#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long
ll N, B;
int matrix[5][5];
int ans_matrix[5][5];

void init() {
    cin>>N>>B;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>matrix[i][j];
            ans_matrix[i][j] = matrix[i][j];
        }
    }
}

void multipleMatrix(bool isOdd){
    int new_matrix[5][5];
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            int temp = 0;
            for(int k = 0; k<N; k++){
                if(isOdd) temp += (ans_matrix[i][k] * matrix[k][j]);
                else temp += (ans_matrix[i][k] * ans_matrix[k][j]);
            }
            new_matrix[i][j] = temp % 1000;
        }
    }
    memcpy(ans_matrix, new_matrix, sizeof(ans_matrix));
}

void solve(ll nowB){
    if(nowB == 1) return;
    
    solve(nowB /2);
    multipleMatrix(false);
    if(nowB % 2  != 0){
        multipleMatrix(true);
        nowB--;
    }
}

int main(){
    FAST;
    init();
    solve(B);
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++) cout<<ans_matrix[i][j] % 1000<<' ';
        cout<<endl;
            
    }
}
