#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,M,Min;
bool broke_button[10];
vector<int> channel;
void Compare_channel(){
    int temp=1;
    int com=0;
    for(int i=0; i<channel.size(); i++)
    {
        com+=(temp*channel[i]);
        temp*=10;
    }
    string s=to_string(com);
    int res=abs(com-N)+s.size();
    Min=min(Min, res);
}

void Remote(int length, bool zero)
{
    if(zero)
        Compare_channel();
    if(length==6)
        return;
    for(int i=0; i<10; i++)
    {
        if(!broke_button[i])
        {
            channel.push_back(i);
            Remote(length+1, true);
            channel.pop_back();
        }
    }
}
int main()
{
    FAST;
    cin>>N>>M;
    int input;
    for(int i=0; i<M; i++)
    {
        cin>>input;
        broke_button[input]=true;
    }
    Min=abs(100-N); // 그냥 가는 경우
    Remote(0,false);
    cout<<Min<<'\n';
}
