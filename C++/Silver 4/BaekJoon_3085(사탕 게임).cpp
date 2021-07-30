#include<bits/stdc++.h>
using namespace std;
int main()
{
    int dis_x[2]={1,0};
    int dis_y[2]={0,1};
    int n,max=0,compare_x=1,x,y,compare_y=1;
    cin>>n;
    string s[n];
    for(int i=0; i<n; i++)
    cin>>s[i];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<2; k++)
            {
                x=i+dis_x[k];
                y=j+dis_y[k];
                if(x<n && y<n && s[i][j]!=s[x][y]) //범위 안에 있으면 인접한 곳끼리 바꿔줌
                {
                    swap(s[i][j], s[x][y]);
                    for(int l=0; l<n; l++) //탐색 시작
                    {
                        for(int h=1; h<n; h++)
                        {
                            if(s[l][h]==s[l][h-1])//행기준으로 카운팅함(전에꺼랑 비교해서 같으면 1증가) //이새끼가 문제임 시발
                                compare_x++;
                            if(s[l][h]!=s[l][h-1] || h==n-1)//전에꺼랑 다르거나 미자믹에 배열의 행의 끝에 도닥했을시에 max와 비교
                            {
                                if(compare_x>max)
                                    max=compare_x;
                                compare_x=1;
                            }
                            if(s[h][l]==s[h-1][l])//열기준으로 카운팅함(전에꺼랑 비교해서 같으면 +1증가).
                                compare_y++;
                            if(s[h][l]!=s[h-1][l] || h==n-1)//전에꺼랑 다르거라 마지막에 배열 열의 끝에 도달했을시에 max와 비교
                            {
                                if(compare_y>max)
                                    max=compare_y;
                                compare_y=1;
                            }
                        }
                    }
                    swap(s[i][j], s[x][y]);
                }
            }
        }
    }
    cout<<max<<'\n';
}
