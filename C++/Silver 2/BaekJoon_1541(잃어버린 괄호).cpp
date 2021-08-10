#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int ans;
string s;

void Solve(){
    int temp = 0;
    int num = 0;
    int comp = 1;
    for(int i = s.size()-1; i>=0; i--){
        if(s[i] == '+'){
            temp += num;
            comp = 1;
            num = 0;
        }
        else if(s[i] == '-'){
            ans -= (temp + num);
            comp = 1;
            temp = 0;
            num = 0;
        }
        else{
            num += (s[i] - '0')*comp;
            comp *= 10;
            
        }
    }
    ans += (num+temp);
}

int main(){
    FAST;
    cin>>s;
    Solve();
    cout<<ans<<endl;
}
