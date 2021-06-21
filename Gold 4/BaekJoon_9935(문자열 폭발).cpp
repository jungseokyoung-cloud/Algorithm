#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
string now, del;
vector<char> ans;

void Solvee(){
    int delsize = del.size()-1;
    
    for(int i=0; i<now.size(); i++){
        ans.push_back(now[i]);
        
        int idx = ans.size()-1;
        if(ans[idx] == del[delsize] && ans.size() >= del.size()){
            bool erase = true;
            for(int j = delsize-1; j>=0 ; j--){
                idx--;
                if(del[j] != ans[idx]){
                    erase = false;
                    break;
                }
            }
            if(erase){
                for(int j=0; j<del.size(); j++){
                    ans.pop_back();
                }
            }
        }
    }
}

int main(){
    FAST;
    cin>>now>>del;
    Solvee();
    if(ans.size() == 0 ) cout<<"FRULA"<<'\n';
    else{
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i];
        }
        cout<<'\n';
    }
}
