#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int floid[51][51];
int ans[51];
int N,Num = INT_MAX;
vector<int> arr;

void FindAns(){
    for(int i = 1; i<=N; i++){
        int res = 0;
        bool canFriend = true;
        for(int j = 1; j<=N; j++){
            if(i == j) continue;
            if(floid[i][j] == 0){
                canFriend = false;
                break;
            }
            res = max(res,floid[i][j]);
        }
        if(canFriend){
            ans[i] = res;
            Num = min(Num, ans[i]);
        }
        
    }
    for(int i = 1; i<=N; i++){
        if(Num == ans[i]) arr.push_back(i);
    }
}

void Input(){
    cin>>N;
    
    for(int i = 1; i<=N; i++){
        fill(floid[i], floid[i] + N+1, INT_MAX);
        floid[i][0] = 0;
    }
    
    while(1){
        int num1,num2;
        cin>>num1>>num2;
        if(num1 == -1 && num2 == -1) break;
        floid[num1][num2] = 1;
        floid[num2][num1] = 1;
    }

}

void Solve(){
    for(int k = 1; k<=N; k++){
        for(int i = 1; i<=N; i++){
            for(int j = 1; j<=N; j++){
                if(i == j || i == k || j == k) continue;
                if(floid[i][k] == INT_MAX || floid[k][j] == INT_MAX) continue;
                if(floid[i][j] <= floid[i][k] + floid[k][j]) continue;

                floid[i][j] = floid[i][k] + floid[k][j];
                floid[j][i] = floid[i][j];
            }
        }
    }
    
   
    FindAns();
}

int main(){
    FAST;
    Input();
    Solve();
    cout<<Num<<' '<<arr.size()<<endl;
    for(auto res : arr) cout<<res<<' ';
    cout<<endl;
}
