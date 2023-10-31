/*
A : array of items
   while interval < A.length /3 do:
      interval = interval * 3 + 1
   end while

   while interval > 0 do:
      for outer = interval; outer < A.length; outer ++ do:
      valueToInsert = A[outer]
      inner = outer;
         while inner > interval -1 && A[inner - interval] >= valueToInsert do:
            A[inner] = A[inner - interval]
            inner = inner - interval
         end while
      A[inner] = valueToInsert

      end for
   interval = (interval -1) /3;

   end while

*/

#include <iostream>
using namespace std;
int main()
{
    int i, n, interval, lenght, outer, valuetoinsert, inner;
    cout << "enter size of array :";
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    while (interval < n / 3)
    {
        interval = (interval * 3) + 1;
    }
    while (interval > 0)
    {
        for (outer = interval; outer < n; outer++)
        {
            valuetoinsert = a[outer];
            inner = outer;
            while (inner > interval - 1 && a[inner - interval] >= valuetoinsert)
            {
                a[inner] = a[inner - interval];
                inner = inner - interval;
            }
            a[inner] = valuetoinsert;

            for (i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }
        interval = (interval - 1) / 3;
    }
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}

// shell sort
