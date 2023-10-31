#include <iostream>
#include <vector>
using namespace std;
void heapefy(vector<int> &array, int i, int n)
{

    int largest = i, left, right;
    left = 2 * i + 1;
    right = 2 * i + 2;
    if (left < n && array[left] > array[largest])
    {
        largest = left;
    }

    if (right < n && array[right] > array[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(array[i], array[largest]);
        heapefy(array, largest, n);
    }
}

void heap(vector<int> &array)
{
    int i, n = array.size();
    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapefy(array, i, n);
    }
    for (i = n - 1; i > 0; i--)
    {
        swap(array[0], array[i]);
        heapefy(array, 0, i);
    }
}

int main()
{
    vector<int> array = {2, 9, 0, 3, 5};
    heap(array);
    for (int a : array)
    {
        cout << a << " ";
    }
    return 0;
}
