#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,ans;
int inputNum = 9;
vector<string> s(11);
int Alpha[27];

bool comp(int a, int b){
    return a > b;
}

void Solve(){
    sort(Alpha, Alpha + 27, comp);
    for(int i = 0; i<27; i++){
        if(Alpha[i] == 0) break;
        ans += (Alpha[i] * inputNum--);
    }
}

int main(){
    FAST;
    cin>>N;
    
    for(int i = 0; i<N; i++){
        cin>>s[i];
        int temp = 1;
        for(int j = s[i].size()-1; j>=0; j--){
            int idx = s[i][j] - 'A';
            Alpha[idx] += temp;
            temp *= 10;
        }
    }
    Solve();
    cout<<ans<<'\n';
}
