#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int train[50001];
int N, Small;
int ans[50001][4];

int Solve(){
    int res = 0;
    for(int i = 1; i<=3; i++){
        for(int j = i*Small; j <=N; j++){
            if(i == 1)
                ans[j][i] = max(ans[j-1][i], train[j]-train[j-Small]);
            else
                ans[j][i] = max(ans[j-1][i], ans[j-Small][i-1] + train[j]-train[j-Small]);
        }
    }
    
    for(int i = 1; i <=N; i++){
        res = max(res, ans[i][3]);
    }
    return res;
}

int main(){
    FAST;
    cin>>N;
    int add = 0, num;
    for(int i=1; i<=N; i++){
        cin>>num;
        train[i] = num + add;
        add = train[i];
    }
    
    cin>>Small;
    cout<<Solve()<<'\n';
}
