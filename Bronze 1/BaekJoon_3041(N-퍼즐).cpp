#include <iostream>
#include<cstdlib>
using namespace std;
 
 
int main()
{
    char puzzle[4][4], solved[4][4]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'};
    int ans =0;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        cin>>puzzle[i][j];
    }
     for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            for(int k=0; k<4; k++)
            {
                for(int l=0; l<4; l++)
                {
                    if(puzzle[i][j]==solved[k][l])
                    {
                        ans += abs(i-k)+abs(j-l);
                    }
               }
            }
        }
    }
    cout<<ans<<'\n';
}
