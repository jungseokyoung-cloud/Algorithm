#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int Z_Array(int n,int r, int c)
{
    if(n==0)
        return 0;
    int half=1<<(n-1);
    if(r<half && c<half) return Z_Array(n-1, r, c);
    if(r<half && c>=half) return half*half+Z_Array(n-1, r, c-half);
    if(r>=half && c<half) return 2*half*half+Z_Array(n-1, r-half, c);
    return 3*half*half+Z_Array(n-1, r-half, c-half);
}

int main()
{
    FAST;
    int N,r,c;
    cin>>N>>r>>c;
    cout<<Z_Array(N, r, c)<<'\n';
}
