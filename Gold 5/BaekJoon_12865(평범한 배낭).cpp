#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 100001
int ans[101][MMAX];
pair<int, int> arr[101]; // 첫번째는 무게 두번째는 가치
int N,K;
void Solve(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=K; j++){
            if(j-arr[i].first>=0) // i번째 무게를 감당가능
            ans[i][j]=max(ans[i-1][j], ans[i-1][j-arr[i].first]+arr[i].second);
            else
                ans[i][j]=ans[i-1][j];
        }
    }
}

int main(){
    FAST;
    cin>>N>>K;
    int w,v;
    for(int i=1; i<=N; i++){
        cin>>w>>v;
        arr[i]={w,v};
    }
    Solve();
    cout<<ans[N][K]<<'\n';
}
