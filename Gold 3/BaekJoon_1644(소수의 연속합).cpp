#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int MMAX =  4000001;
vector<int> primeNum;
bool Prime[MMAX];
int N,ans;

void FindPrimeNum(){
    for(int i = 2; i< MMAX; i++){
        if(Prime[i]) continue;
        primeNum.push_back(i);
        for(int j = 2; j*i < MMAX; j ++){
            Prime[j*i] = true;
        }
    }
}

void Solve(){
    int left = 0;
    int right = 0;
    int sum = 0;
    while(primeNum[left] <= N){
        if(right == primeNum.size() && sum < N)  return;
        if(sum < N){
            sum += primeNum[right++];
        }
        else if(sum > N){
            sum -= primeNum[left++];
        }
        else if(sum == N){
            ans ++;
            sum -= primeNum[left++];
        }
    }
}

int main(){
    FindPrimeNum();
    cin>>N;
    Solve();
    cout<<ans<<'\n';
}
