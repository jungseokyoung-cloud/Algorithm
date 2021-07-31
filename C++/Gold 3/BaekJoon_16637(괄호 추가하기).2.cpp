#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N,ans = INT_MIN;
bool isused[20];
vector<char> sign;
vector<int> num;

void Input(){
    cin>>N;
    
    for(int i = 0; i<N; i++){
        char c;
        cin>>c;
        
        if('0' <= c && c <= '9') num.push_back(c-'0');
        else sign.push_back(c);
    }
}

int Calculate(int num1, int num2, char Sign){
    if(Sign == '+') return num1 + num2;
    else if(Sign == '-') return num1 - num2;
    else return num1 * num2;
}

void Result(){
    int sum = num[0];
    for(int i = 0; i<sign.size(); i++){
        if(i<sign.size()-1 && isused[i+1]){
            int temp = Calculate(num[i+1], num[i+2], sign[i+1]);
            sum = Calculate(sum, temp , sign[i]);
            i++;
        }
        else sum = Calculate(sum, num[i+1], sign[i]);
    }
    ans = max(ans, sum);
}

void DFS(int idx){
    
    if(idx >= sign.size()){
        Result();
        return;
    }
    
    isused[idx] = true;
    DFS(idx+2);
    isused[idx] = false;
    DFS(idx+1);
}

int main(){
    FAST;
    Input();
    DFS(0);
    cout<<ans<<endl;
}
