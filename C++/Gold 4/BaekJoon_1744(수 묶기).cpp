#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N, ans, zeroCnt;
priority_queue<int> Plus;
priority_queue<int> Minus;

void Solve(){
    while(Plus.size() > 1){
        int num1 = Plus.top();  Plus.pop();
        int num2 = Plus.top();  Plus.pop();
        
        int temp = max(num1 + num2, num1 * num2);
        ans+=temp;
    }
    if(!Plus.empty()){
        ans += Plus.top();  Plus.pop();
    }
    
    while(Minus.size() > 1){
        int num1 = -Minus.top();  Minus.pop();
        int num2 = -Minus.top();  Minus.pop();
        
        ans+=num1 * num2;
    }
    if(!Minus.empty() && zeroCnt == 0){
        ans -= Minus.top();
    }
}

int main(){
    FAST;
    cin>>N;
    int a;
    for(int i = 0; i<N; i++){
        cin>>a;
        if(a == 0) zeroCnt ++ ;
        else if(a > 0) Plus.push(a);
        else Minus.push(-a);
    }
    Solve();
    cout<<ans<<endl;
}
