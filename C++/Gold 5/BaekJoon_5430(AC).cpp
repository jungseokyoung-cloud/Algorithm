#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main()
{
    FAST;
    int T,arr_size;
    string order,arr;// order는 명령어 s는 배열
    cin>>T;
    while(T--)
    {
        bool ans=true;
        int rev=0; //rev가 짝수면 원래대로 홀수면 뒤바뀜
        deque<int> dq;
        cin>>order;
        cin>>arr_size;
        cin>>arr;
        for(int i=1; i<arr.size(); i++) // 저장
        {
            int num=0;
            while(arr[i]>='0' && arr[i]<='9')
            {
                num*=10;
                num+=(arr[i]-'0');
                i++;
            }
            if(num!=0)
                dq.push_back(num);
        }
        for(auto c: order)
        {
            if(c=='R')
                rev++;
            else if(c=='D' && !dq.empty()) //비어 있지 않다면!
            {
                if(rev%2==0) // 짝수 이면 원래대로.
                    dq.pop_front();
                else // 홀수면 뒤바뀜
                    dq.pop_back();
            }
            else if(c=='D' && dq.empty())
            {
                ans=false;
                break;
            }
        }
        if(ans) // true라면 정상임
        {
            cout<<"[";
            if(rev%2==0)
            {
                for(int i=0; i<dq.size(); i++)
                {
                    if(i==dq.size()-1)
                        cout<<dq[i];
                    else
                        cout<<dq[i]<<",";
                }
            }
            else
            {
                for(int i=dq.size()-1; i>=0; i--)
                {
                    if(i==0)
                        cout<<dq[i];
                    else
                        cout<<dq[i]<<",";
                }
            }
            cout<<"]"<<'\n';
        }
        else
            cout<<"error"<<'\n';
    }
}
