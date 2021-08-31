#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int arr[4][4000];
int N;
long long ans;
vector<int> totalA,totalB;

void Input(){
    cin>>N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<4; j++){
            cin>>arr[j][i];
        }
    }
}

void Setting(){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            totalA.push_back(arr[0][i] + arr[1][j]);
            totalB.push_back(arr[2][i] + arr[3][j]);
        }
    }
    sort(totalA.begin(), totalA.end());
    sort(totalB.begin(), totalB.end());
}

void Solve(){
    for(int i = 0; i<totalA.size(); i++){
        int target = totalA[i];
        int upper = upper_bound(totalB.begin(), totalB.end(), -target) - totalB.begin();
        int lower = lower_bound(totalB.begin(), totalB.end(), -target) - totalB.begin();
        ans += (upper - lower);
    }
}

int main(){
    FAST;
    Input();
    Setting();
    Solve();
    cout<<ans<<endl;
}
