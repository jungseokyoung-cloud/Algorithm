#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
string s1,s2,ans;
bool res;
int check[60];
bool Different(){
    for(int i=0; i<ans.size(); i++)
    check[ans[i]-'A']++;
    for(int i=0; i<s1.size(); i++)
    check[s1[i]-'A']--;
    for(int i=0; i<s2.size(); i++)
    check[s2[i]-'A']--;
    for(int i=0; i<60; i++)
    {
        if(check[i]>0){
            return false;
        }
    }
    return true;
}
void Solve(int idx, int idx1, int idx2){

    if(idx==ans.size() || res)
    {
        res=true;
        return;
    }
    if(idx1<s1.size() && ans[idx]==s1[idx1])
        Solve(idx+1, idx1+1, idx2);
    if(idx2<s2.size() && ans[idx]==s2[idx2])
        Solve(idx+1, idx1, idx2+1);
}
int main(){
    FAST;
    int T;
    cin>>T;
    for(int i=1; i<=T; i++){
        cin>>s1>>s2>>ans;
        res=false;
        memset(check, 0, sizeof(check));
        if(Different())
            Solve(0, 0, 0);
        cout<<"Data set "<<i<<": ";
        if(res)
            cout<<"yes"<<'\n';
        else
            cout<<"no"<<'\n';
    }
}
