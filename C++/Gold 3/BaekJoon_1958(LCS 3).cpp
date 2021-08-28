#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int dp[101][101][101];
string s1,s2,s3;
int ans;

void Solve(){
    for(int i = 0; i<s1.size(); i++){
        for(int j = 0; j<s2.size(); j++){
            for(int k = 0; k<s3.size(); k++){
                if(s1[i] == s2[j] && s1[i] == s3[k])  dp[i+1][j+1][k+1] = dp[i][j][k] + 1;
                else{
                    dp[i+1][j+1][k+1] = max(dp[i+1][j+1][k], dp[i+1][j][k+1]);
                    dp[i+1][j+1][k+1] = max(dp[i+1][j+1][k+1], dp[i][j+1][k+1]);
                }
               
                ans = max(dp[i+1][j+1][k+1], ans);
            }
        }
    }
}

int main(){
    FAST;
    cin>>s1>>s2>>s3;
    Solve();
    cout<<ans<<endl;
}
