#include<bits/stdc++.h>
using namespace std;
bool BinarySearch(vector<int>&ref, int target)
{
    int low=0;
    int high=ref.size()-1;
    int middle;
    while(low<=high)
    {
        middle=(low+high)/2;
        if(target==ref[middle])
            return true;
        else if(target>ref[middle])
            low=middle+1;
        else
            high=middle-1;
    }
    return false;
}
int main()
{
    int n,x,target,cnt=0;
    bool ans;
    cin>>n;
    vector<int>v(n,0);
    for(int i=0; i<n; i++)
    cin>>v[i];
    cin>>x;
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++)
    {
        target=x-v[i];   //음수가 나올수 없음.
        if(target>0)
        {
        ans=BinarySearch(v, (x-v[i]));
            if(ans)
                cnt++;
        }
    }
    cout<<cnt/2<<'\n';
}
