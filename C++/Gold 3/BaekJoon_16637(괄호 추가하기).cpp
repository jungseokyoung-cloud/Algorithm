#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N;
int ans[20][2];
vector<char> sign;
vector<int> num;

int Calculater(int st, int en, int idx){
    if(sign[idx] == '-') return st - en;
    else if(sign[idx] == '+') return st + en;
    else return st * en;
}

void Input(){
    cin>>N;
    
    for(int i = 0; i<N; i++){
        char c;
        cin>>c;
        
        if('0' <= c && c <= '9') num.push_back(c-'0');
        else sign.push_back(c);
    }
}

void Solve(){
    
    ans[0][0] = ans[0][1] =  num[0];
    if(N == 1) return;
    ans[1][0] = ans[1][1] = Calculater(ans[0][0], num[1], 0);
    
    for(int i = 2; i < num.size(); i++){
        int temp = Calculater(num[i-1], num[i], i-1);
        int bigger = max(Calculater(ans[i-1][0], num[i], i-1), Calculater(ans[i-2][0], temp, i-2));
        int bigger2 = max(Calculater(ans[i-1][1], num[i], i-1), Calculater(ans[i-2][1], temp, i-2));
        if(bigger < bigger2) bigger = bigger2;
        ans[i][0] = bigger;
        
        int smaller = min(Calculater(ans[i-1][0], num[i], i-1), Calculater(ans[i-2][0], temp, i-2));
        int smaller2 = min(Calculater(ans[i-1][1], num[i], i-1), Calculater(ans[i-2][1], temp, i-2));
        if(smaller > smaller2) smaller = smaller2;
        ans[i][1] = smaller;
    }
}

int main(){
    FAST;
    Input();
    Solve();
    int numsize = N/2;
    cout<<ans[numsize][0]<<'\n';
}
