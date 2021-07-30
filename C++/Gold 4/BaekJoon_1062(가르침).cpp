#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,K,ans;
string s[50];
bool willUsed[26];
vector<char> res;

int Check(){
    int cnt = N;
    for(int i=0; i<N; i++){
        for(int j=0; j<s[i].size(); j++){
            bool result = true;
            for(int k=0; k<res.size(); k++){
                if(res[k] != s[i][j]) continue;
                result = false;
                break;
            }
            if(result){
                cnt--;
                break;
            }
        }
    }
    
    return cnt;
}

void Solve(int cnt, int idx){
    if(cnt == K){
        int comp = Check();
        ans = max(comp, ans);
        return;
    }
    
    for(int i=idx; i<26; i++){
        if(!willUsed[i]) continue;
        res.push_back(i+'a');
        Solve(cnt+1, i+1);
        res.pop_back();
    }
}

int main(){
    FAST;
    cin>>N>>K;
    int cnt = 0;
    for(int i=0; i<N; i++){
        cin>>s[i];
        for(int j=0; j<s[i].size(); j++){
            if(s[i][j]=='a' || s[i][j] == 'n'|| s[i][j] == 't' || s[i][j] == 'i' || s[i][j] == 'c')
                continue;
            int idx = s[i][j]-'a';
            if(willUsed[idx]) continue;
            willUsed[idx] = true;
            cnt++;
        }
    }
    res.push_back('a');
    res.push_back('n');
    res.push_back('t');
    res.push_back('i');
    res.push_back('c');
    
    if(K<5) ans = 0;
    else if(cnt <= K-5) ans = N;
    else    Solve(5,0);
    cout<<ans<<'\n';
}
