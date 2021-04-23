#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int main()
{
    FAST;
    int x1,x2,r1,r2,y1,y2,t,dis1,dis2,d; //원이 내접하는지 외접하는지 알아봐야하는데 어떻게 알 수가 있을까!
    cin>>t;
    for(int i=0; i<t; i++)
    {
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);  //두 원의 중심간의 거리
        dis1=(r1+r2)*(r1+r2);
        dis2=(r1-r2)*(r1-r2);
        if(x1==x2 && y1==y2 && r1==r2)
            cout<<"-1"<<'\n';
        else if(dis2<d && d<dis1)
            cout<<"2"<<'\n';
        else if(dis2>=d) //이경우는 내접하는 경우
        {
            if(dis2==d)
                cout<<"1"<<'\n';
            else
                cout<<"0"<<'\n';

        }
        else if(dis1<=d) //이경우에는 외접하는 경우
        {
            if(dis1==d)
                cout<<"1"<<'\n';
            else
                cout<<"0"<<'\n';
        }
    }
}
