#include <iostream>
#include<vector>
#include<algorithm>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int solution(vector<int> v, int start, int target) {
    int end = v.size() - 1;
    int mid;
    while (start <= end) {
        mid = (start + end) / 2;
        if (v[mid] <= target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return end;
}
int main()
{
    int n,result=0,start_x=0,end_x,start_y=0,end_y;
    cin>>n;
    end_x=n;
    end_y=n;
    FAST;
    vector <int> pos_x(n);
    vector <int> pos_y(n);
    for(int i=0; i<n; i++)
        cin>>pos_x[i]>>pos_y[i];
    sort(pos_x.begin(), pos_x.end());
    sort(pos_y.begin(), pos_y.end());
    while(start_x<n)
    {
        end_x=solution(pos_x, start_x, pos_x[start_x]);
        if((end_x-start_x)>=1)
            result++;
        start_x=(end_x+1);
    }
    while(start_y<n)
    {
        end_y=solution(pos_y, start_y, pos_y[start_y]);
        if((end_y-start_y)>=1)
            result++;
        start_y=(end_y+1);
    }
    cout<<result<<endl;
}
