#include<iostream>
using namespace std;
int main()
{
    int array[]= {2,4,0,5,-10}, i,j, size=5, temp;

    for(i=0; i<size; i++)
    {
        for(j=0; j<size-1; j++)
        {
            if(array[j]>array[j+1])
            {
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
    for(i=0; i<size; i++)
    {
        cout<<array[i]<<" ";
    }
    return 0;
}
