#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main()
{
    FAST;
    int index=1;
    string s;
    while(1)
    {
        int cnt=0;
        bool ans=false;
        cin>>s;
        stack<char> st;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='-')
            {
                ans=true;
                break;
            }
            if(s[i]=='{')
                st.push(s[i]);
            else if(s[i]=='}')
            {
                if(st.empty() || st.top()=='}')
                    st.push(s[i]);
                else if(!st.empty() && st.top()=='{')
                    st.pop();
            }
        }
        if(ans) //'-'가 입력된 경우
            break;
        char c;
        if(!s.empty()) // 비어 있지 않다면 연산이 필요한 경우이다.
        {
            while(!st.empty()) //size/2만큼 진행
            {
                c=st.top();
                st.pop();
                if(c==st.top()) // 전과 같을 경우에는 연산을 한번만 진행해주면 된다.
                    cnt+=1;
                else // 서로 다를 경우 두개다 바꿔 주어야한다.
                    cnt+=2;
                st.pop();
            }
        }
        cout<<index<<". "<<cnt<<'\n';
        index++;
    }
}
