#include <iostream>
using namespace std;
int main()
{
    int array[] = {-5, 78, 5, -4, 6}, i, j, k, size = 5;
    for (i = 0; i < size; i++)
    {
        k = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > k)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = k;
    }

    for (i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}
