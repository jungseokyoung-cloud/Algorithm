#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main()
{
    FAST;
    int res=0,n;
    cin>>n;
    string s;
    for(int i=0; i<n; i++)
    {
        stack<char>first;
        cin>>s;
        for(int j=0; j<s.size(); j++)
        {
           if(!first.empty() && s[j]==first.top()) //맨위의 숫자가 같다면 지움
               first.pop();
            else
                first.push(s[j]);
        }
        if(first.empty()) //만약에 다비어있다면 좋은 단어임
            res++;
    }
    cout<<res<<'\n';
}
/* if(!first.empty() && s[j]==first.top())
 --> if문에서 첫번째 조건부터 확인해서 이거 바뀌면 컴파일 에러뜸 신기함
 */
