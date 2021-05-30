#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
char gear[4][8];
int top[4]; // 4개의 톱니바퀴의 가장위의 인덱스 저장
int score;
int vis[4];
void Find_left(int &left, int num){
    left=top[num]-2;
    if(left<0)  left+=8;
   
}
void Find_right(int &right, int num){
    right=top[num]+2;
    if(right>7) right-=8;
}
void Check_Gear(int num, int dir)
{
    vis[num]=true;
    int left,right;
    Find_left(left,num);
    Find_right(right,num);
    if(num>0 && !vis[num-1]) //왼쪽이 있는경우!
    {
        int lright;
        Find_right(lright,num-1);
        if(gear[num][left]!=gear[num-1][lright])
            Check_Gear(num-1, dir*-1);
    }
    if(num<3 && !vis[num+1])
    {
        int lleft;
        Find_left(lleft, num+1);
        if(gear[num+1][lleft]!=gear[num][right])
            Check_Gear(num+1, dir*-1);
    }
    
    
    if(dir==1){
        top[num]-=1;
        if(top[num]<0) top[num]+=8;
    }
    else{
        top[num]+=1;
        if(top[num]>7) top[num]-=8;
    }
}
void Add_Score()
{
    int temp=1;
    for(int i=0; i<4; i++)
    {
        if(gear[i][top[i]]=='1')
            score+=temp;
        temp*=2;
    }
}
int main()
{
    FAST;
    int K,dir,num;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<8; j++)
        cin>>gear[i][j];
    }
    cin>>K;
    for(int i=0; i<K; i++)
    {
        cin>>num>>dir;
        memset(vis, false, sizeof(vis));
        Check_Gear(num-1, dir);
    }
    Add_Score();
    cout<<score<<'\n';
}
