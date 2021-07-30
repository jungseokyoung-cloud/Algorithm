#include <iostream>
#include <string>
#include <stack>
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
string s,postfix;
stack<char> symbol;

void Solve(){
    for(int i=0; i<s.size(); i++){
        if(s[i]>='A' && s[i]<='Z'){
            postfix.push_back(s[i]);
        }
        
        else if(s[i]=='+' || s[i]=='-'){
            while(1){
                if(symbol.empty() || symbol.top()=='(') break;
                postfix.push_back(symbol.top());
                symbol.pop();
            }
            symbol.push(s[i]);
        }
        
        else if(s[i]=='(') symbol.push(s[i]);
        
        else if(s[i]=='*' || s[i]=='/'){
            if(!symbol.empty() && (symbol.top()=='*' || symbol.top()=='/')){
                postfix.push_back(symbol.top());
                symbol.pop();
            }
            symbol.push(s[i]);
        }
        
        else if(s[i]==')'){
            while(1){
                if(symbol.top()=='('){
                    symbol.pop();
                    break;
                }
                postfix.push_back(symbol.top());
                symbol.pop();
            }
        }
    }
    while(!symbol.empty()){
        postfix.push_back(symbol.top());
        symbol.pop();
    }
}

int main() {
    FAST;
    cin>>s;
    Solve();
    cout<<postfix<<'\n';
}
