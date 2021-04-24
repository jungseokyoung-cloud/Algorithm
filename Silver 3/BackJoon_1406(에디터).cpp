#include <bits/stdc++.h>
using namespace std;

const int MX = 1000000;
int pre[MX], nxt[MX];
char dat[MX];
int unused = 1;
void insert(int addr, char num){
    pre[unused]=addr; //전의 주솟값은 addr
    dat[unused]=num;
    nxt[unused]=nxt[addr]; //다음이 가르키는 주솟값은, addr이 가르켰던 주소가 된다.
    if(nxt[addr]!=-1) // 만약 전이 마지막이였다면! 다음이 가르키는 전의 값은 내가 되어야한다.
    pre[nxt[addr]]=unused; //
    nxt[addr]=unused; //전의 다음이 가르키는 주솟값은 현재가 되어야함.
    unused++;
}

void erase(int addr){  //해당 주솟값을 지움. 전의 주솟값 pre[addr] 다음 주솟값 nxt[addr]
    nxt[pre[addr]]=nxt[addr];
    if(nxt[addr]!=-1)
    pre[nxt[addr]]=pre[addr];
}

void traverse(){
  int cur = nxt[0];
  while(cur != -1){
    cout << dat[cur];
    cur = nxt[cur];
  }
  cout << "\n";
}
int main()
{
    fill(pre,pre+MX,-1);
    fill(nxt,nxt+MX,-1);
    string s,s2;
    int t;
    int cusor=0;
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        insert(i, s[i]);
        cusor=i+1;
    }
    cin>>t;
    for(int i=0; i<t; i++)
    {
        cin>>s;
        if(s[0]=='P')
        {
            cin>>s;
            insert(cusor, s[0]);
            cusor=nxt[cusor];
        }
        else if(s[0]=='B' && cusor!=0)
       {
           erase(cusor);
           cusor=pre[cusor];
       }
       else if(s[0]=='L' && pre[cusor]!=-1){
           cusor=pre[cusor];
       }
        else if(s[0]=='D' && nxt[cusor]!=-1)
            cusor=nxt[cusor];
    }
    traverse();
}
