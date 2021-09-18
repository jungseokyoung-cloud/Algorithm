#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N;
int arr[100000];

void Solve(){
    priority_queue<int> upper; // 작은 애들 저장
    priority_queue<int> lower; // 큰 애들 저장
    
    for(int i = 0; i<N; i++){
        if(upper.size() == lower.size()) upper.push(arr[i]);
        else lower.push(-arr[i]);
        
        if(!lower.empty() && !upper.empty()){
            int upperTop = upper.top();
            int lowerTop = -lower.top();
            if(upperTop > lowerTop){
                upper.pop();
                lower.pop();
                upper.push(lowerTop);
                lower.push(-upperTop);
            }
        }
        cout<<upper.top()<<endl;
    }

}

int main(){
    FAST;
    cin>>N;
    for(int i = 0; i<N; i++) cin>>arr[i];
    Solve();
}
