#include<iostream>
using namespace std;
int main()
{

    int array[]= {4,-56,8,1,9},i,j,midx,temp,size=5;
    for(i=0; i<size; i++)
    {
        midx=i;
        for(j=i+1; j<size; j++)
        {
            if(array[j]<array[midx])
            {

                midx=j;
            }
        }
        temp=array[i];
        array[i]=array[midx];
        array[midx]=temp;
    }

    for(i=0; i<size; i++)
    {
        cout<<array[i]<<" ";
    }
    return 0;
}
