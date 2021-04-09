#include<iostream>
#include<string>
using namespace std;
int main()
{
    int result=0,cnt=0;
    string s1;
    int n,idx;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cnt=0;
        int s2[26]={0,};
        cin>>s1;
        for(int j=0; j<s1.size(); j++)
        {
            idx=s1[j]-'a';
            if(j==0)
              s2[idx]+=1;
            else
            {
                if(s1[j]!=s1[j-1])
                    s2[idx]+=1;
            }
            if(s2[idx]>1)
            {
                cnt++;
                break;
            }
        }
        if(cnt==0)
            result++;
    }
    cout<<result<<endl;
}
