#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
bool BinarySearch(vector<int>&v,int target)
{
    FAST;
    int low=0;
    int high=v.size()-1;
    int middle;
    while(low<=high)
    {
        middle=(low+high)/2;
        if(target==v[middle])
            return true;
        else if(target>v[middle])
            low=middle+1;
        else if(target<v[middle])
            high=middle-1;
    }
    return false;
}
int main()
{
    int n,m;
    bool ans;
    cin>>n;
    vector<int>v(n,0);
    for(int i=0; i<n; i++)
    cin>>v[i];
    sort(v.begin(), v.end()); //정렬
    cin>>m;
    vector<int>v2(m,0);
    for(int i=0; i<m; i++)
    cin>>v2[i];
    for(int i=0; i<m; i++) //서치
    {
        ans=BinarySearch(v, v2[i]);
        if(ans)
            cout<<"1"<<'\n';
        else
            cout<<"0"<<'\n';
    }
}
