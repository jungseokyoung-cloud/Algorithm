#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
const ll divide = 1000000003;
int color[1001][1001]; //i 개의 색중 j를 선택하는 경우의 수
int N,K;

void Solve(){
    for(int i = 4; i<=N; i++){
        for(int j = 2; j<=K; j++){
            color[i][j] = (color[i-1][j] + color[i-2][j-1])%divide;
        }
    }
}

int main(){
    FAST;
    cin>>N>>K;
    for(int i = 1; i<=N; i++){
        color[i][1] = i;
        color[i][0] = 1;
    }
    Solve();
    cout<<color[N][K]<<'\n';
}
