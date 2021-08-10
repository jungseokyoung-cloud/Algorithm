#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int floid[20][20];
bool choice[20][20];
int N,ans;

void Solve(){
    for(int k = 0; k<N; k++){
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                if(i == j || i == k || k == j) continue;
                if(floid[i][j] > floid[i][k] + floid[k][j]){
                    ans = -2;
                    return;
                }
               else if(floid[i][j] == floid[i][k] + floid[k][j]) choice[i][j] = true;
            }
        }
    }

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(choice[i][j]) continue;
            ans += floid[i][j];
        }
    }

}

int main(){
    FAST;
    cin>>N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>floid[i][j];
        }
    }
    Solve();
    cout<<ans/2<<endl;
}
