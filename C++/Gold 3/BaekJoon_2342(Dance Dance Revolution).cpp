#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int arr[100001];
int dp[5][5][100001];
int ans = INT_MAX;
int idx;

void Input(){
    while(1){
        int num;
        cin>>num;
        if(num == 0){
            arr[idx] = -1;
            break;
        }
        arr[idx] = num;
        idx ++;
    }
    memset(dp, -1, sizeof(dp));
}

int checkNextValue(int now, int next){
    if(now == 0) return 2;
    else if(now == next) return 1;
    else if(abs(now - next) == 2) return 4;
    else return 3;
}

void Solve(){
    if(arr[0] == -1){
        ans = 0;
        return;
    }
    dp[0][arr[0]][0] = 2;
    for(int now = 1; now<idx; now++){
        int next = arr[now];
        for(int i = 0; i<5; i++){
            for(int j = 0; j<5; j++){
                if(dp[i][j][now - 1] == -1) continue;

                int temp = dp[i][j][now-1] + checkNextValue(i, next);
                int temp2 = dp[i][j][now-1] + checkNextValue(j, next);
                if(dp[next][j][now] == -1) dp[next][j][now] = INT_MAX;
                if(dp[i][next][now] == -1) dp[i][next][now] = INT_MAX;
                dp[next][j][now] = min(dp[next][j][now], temp);

                dp[i][next][now] = min(dp[i][next][now], temp2);
            }
        }
    }
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            if(dp[i][j][idx-1] == -1) continue;
            ans = min(ans, dp[i][j][idx-1]);
        }
    }
}

int main(){
    FAST;
    Input();
    Solve();
    cout<<ans<<endl;
}
