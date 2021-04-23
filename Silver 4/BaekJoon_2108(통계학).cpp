#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,median,range,mode,max=0,cnt=0;
    int arr[8001]={0,};
    long long sum=0;
    double average;
    cin>>n;
    vector<int> v(n,0);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
        sum+=v[i];
        arr[v[i]+4000]+=1;
    }
    sort(v.begin(), v.end());
    range=v.back()-v.front(); // 범위
    median=v[n/2]; //중앙값
    for(int i=0; i<8001; i++)
    {
        if(max<arr[i] && arr[i]>0)
        {
            max=arr[i];
            mode=i-4000;
            cnt=1;
        }
        else if(max==arr[i] && cnt==1 && arr[i]>0)
        {
            mode=i-4000;
            cnt++;
        }
    }
    average=(double)sum/n;
    if(average>=0)
    average=round(average);
    else
    {
        if(abs(average-(int)average)>0.5)
            average=(int)average-1;
        else
            average=(int)average;
    }
    cout<<average<<'\n'<<median<<'\n'<<mode<<'\n'<<range<<'\n';
}
