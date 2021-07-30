#include <iostream>
#include<vector>
#include<algorithm>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main()
{
    int n,result=0,cnt=0,cnt_y=0;
    cin>>n;
    FAST;
    vector <int> pos_x(n);
    vector <int> pos_y(n);
    for(int i=0; i<n; i++)
        cin>>pos_x[i]>>pos_y[i];
    sort(pos_x.begin(), pos_x.end());
    sort(pos_y.begin(), pos_y.end());
    for(int i=1; i<n; i++)
    {
        if(pos_x[i]==pos_x[i-1])
        {
            if(cnt==0)
            {
            cnt=1;
            result++;
            }
        }
        else
            cnt=0;
        if(pos_y[i]==pos_y[i-1])
        {
            if(cnt_y==0)
            {
            cnt_y=1;
            result++;
            }
        }
        else
            cnt_y=0;
    }
    cout<<result<<endl;
}
