 #include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int main()
{
    FAST;
    int n;
    cin>>n;
    vector<int> v(n+1);
    int score[301]={0,};
    for(int i=1; i<=n; i++)
        cin>>v[i];
    score[1]=v[1];
    score[2]=v[1]+v[2];
    score[3]=max(v[2]+v[3], v[1]+v[3]);
    for(int i=4; i<=n; i++)
    score[i]=max(score[i-2]+v[i], score[i-3]+v[i-1]+v[i]); //i-1계단을 밟았을 경우와 밟지 않았을 경우.
    cout<<score[n]<<'\n';
}
