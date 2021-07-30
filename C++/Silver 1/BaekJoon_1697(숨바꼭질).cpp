#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 100001
int dis(int x, int idx)
{
    if(idx==0)
        return x+1;
    else if(idx==1)
        return x-1;
    else
        return x*2;
}
int arr[MMAX];
int main()
{
    fill(arr, arr+MMAX, -1);
    int n,k; //k는 동생
    cin>>n>>k;
    queue<int> pos;
    pos.push(n);
    arr[n]=0;
    while(!pos.empty())
    {
        int x=pos.front();
        pos.pop();
        if(x==k)
        {
            cout<<arr[x]<<'\n';
            return 0;
        }
        for(int i=0; i<3; i++)
        {
            int nx=dis(x, i);
            if(nx<0 || nx>=MMAX) continue;
            if(arr[nx]>=0) continue;
            pos.push(nx);
            arr[nx]=arr[x]+1;
        }
    }
}
