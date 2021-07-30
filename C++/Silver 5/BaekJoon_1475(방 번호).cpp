#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int cnt=0,cnt2=0,cnt_ans,idx=0;
    cin>>s;
    int arr[9]={0,};
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='6' || s[i]=='9')
            cnt++;
        else
        {
            idx=s[i]-'0';
            arr[idx]+=1;
            if(cnt2<=arr[idx])
                cnt2=arr[idx];
        }
    }

    if(cnt%2==0)
        cnt_ans=cnt/2;
    else
        cnt_ans=cnt/2+1;
    if(cnt_ans>cnt2)
        cout<<cnt_ans<<'\n';
    else
        cout<<cnt2<<'\n';
}
