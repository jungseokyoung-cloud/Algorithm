#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long
const ll divide = 1000000007;
struct Matrix{
    ll mat[2][2];
};
ll N;
Matrix ans;

Matrix operator* (const Matrix& a,const Matrix& b){
    Matrix temp;
    for(int i = 0; i<2; i++){
        for(int j = 0; j<2; j++){
            temp.mat[i][j] = 0;
            for(int k = 0; k<2; k++){
                temp.mat[i][j] += a.mat[i][k] * b.mat[k][j];
            }
            temp.mat[i][j] %= divide;
        }
    }
    return temp;
}

Matrix Solve(Matrix a, ll cnt){
    if(cnt == 1) return a;
    if(cnt % 2 == 1) return Solve(a, cnt-1) * a;
    Matrix half = Solve(a, cnt/2);
    return half * half;
}

int main(){
    FAST;
    cin>>N;
    ans.mat[0][0] = 1;
    ans.mat[0][1] = 1;
    ans.mat[1][0] = 1;
    ans.mat[1][1] = 0;
    
    ans = Solve(ans, N);
    
    cout<<ans.mat[0][1]<<endl;
}
