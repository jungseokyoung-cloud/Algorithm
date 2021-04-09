#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>
#include<string.h>
using namespace std;
using ll=long long;
#define Max 100001
int main()
{
    ll dis_x[5]={0,0,0,1,-1};
    ll dis_y[5]={0,-1,1,0,0};
    int n,ex,ey,nx,ny;
    cin>>n;
    vector<pair<ll, ll>>pos(n+1);
    ll distance[n+1][5];
    memset(distance, 0x3f3f3f3f3f, sizeof(distance));
    for(int i=0; i<n+1; i++)
    {
        cin>>pos[i].first>>pos[i].second;
       if(i==1)
        {
            for(int j=0; j<5; j++)
            {
                nx=pos[1].first+dis_x[j];
                ny=pos[1].second+dis_y[j];
                if(1<=nx && nx<Max && 1<=ny && ny<Max)
                    distance[1][j]=abs(pos[0].first-nx)+abs(pos[0].second-ny);
            }
        }
        else if(i>=2)
        {
            for(int j=0; j<5; j++)
            {
                nx=pos[i].first+dis_x[j];
                ny=pos[i].second+dis_y[j];
                if(1<=nx && nx<Max && 1<=ny && ny<Max)
                {
                    for(int k=0; k<5; k++)
                    {
                        ex=pos[i-1].first+dis_x[k];
                        ey=pos[i-1].second+dis_y[k];
                        if(1<=ex && ex<Max && 1<=ey && ey<Max)
                            distance[i][j]=min(distance[i][j], distance[i-1][k]+abs(nx-ex)+abs(ny-ey));
                    }
                }
            }
        }
    }
    cout << *min_element(&distance[n][0], &distance[n][0] + 5)<<'\n';
}
