#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
struct Ball{
    int color, value, idx;
};
Ball arr[200001];
int ans[200001];
int sum[200001];
int N;

bool comp(Ball a, Ball b){
    if(a.value == b.value) return a.color < b.color;
    return a.value < b.value;
}

void Solve(){
    sort(arr, arr+N, comp);

    int add = arr[0].value;
    int temp = arr[0].value; // 중복된값 빼줌 이제 중복되면서
    sum[arr[0].color] = arr[0].value;
    int same = 0;
    for(int i = 1; i<N; i++){
        if(arr[i].value != arr[i-1].value){
            temp = 0;
        }
        if(arr[i].value == arr[i-1].value && arr[i].color == arr[i-1].color){
            same += arr[i].value;
        }
        else same = 0;
        ans[arr[i].idx] = add - sum[arr[i].color] - temp + same;
        add += arr[i].value;
        temp += arr[i].value;
        sum[arr[i].color] += arr[i].value;
    }
}

int main(){
    FAST;
    cin>>N;
    for(int i = 0; i<N; i++){
        int num1,num2;
        cin>>num1>>num2;
        arr[i] = {num1,num2,i};
    }
    Solve();
    for(int i = 0; i<N; i++)    cout<<ans[i]<<endl;
}
