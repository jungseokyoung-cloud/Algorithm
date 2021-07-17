#include <iostream>
using namespace std;

int main()
{
    int size;
    int temp_cnt=1;
    cin>>size;
    int i=0,j=0;
    int arr[size][size];
    int direction=0;
    for(int cnt=1; cnt<=size*size; cnt++)
    {
        arr[i][j]=cnt;
        if(direction==0)
        {
            j++;
            if(j==size-temp_cnt)
                direction=1;
        }
        else if(direction==1)
        {
            i++;
            if(i==size-temp_cnt)
                direction=2;
        }
        else if(direction==2)
        {
            j--;
            if(j==temp_cnt-1)
                direction=3;
        }
        else if(direction==3)
        {
            i--;
            if(i==temp_cnt)
            {
                direction=0;
                temp_cnt++;
            }
        }
    }
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        cout<<arr[i][j]<<' ';
        cout<<endl;
    }
    
}
//한 문장안에 if문을 여러개 두면 다 검사함 하지만 if else if 문으로 설정하면 조건이 맞을시 나머지 조건문은 건너뜀
