#include <stdio.h>

void binPacking(int n, int a[], int size)
{
     int count = 0;
     int binValue[n];

     for (int i = 0; i < n; i++)
     {
          binValue[i] = size;
     }

     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < n; j++)
          {
               if (binValue[j] - a[i] >= 0)
               {
                    binValue[j] -= a[i];
                    break;
               }
          }
     }

     for (int i = 0; i < n; i++)
     {
          if (binValue[i] != size)
          {
               count++;
          }
     }

     printf("Value = %d", count);
}

int main()
{
     int n, size;

     printf("How many groups are there: ");
     scanf("%d", &n);

     int a[n];

     for (int i = 0; i < n; i++)
     {
          scanf("%d", &a[i]);
     }

     printf("Enter size: ");
     scanf("%d", &size);

     for (int i = 1; i < n; i++)
     {
          for (int j = i - 1; j < n; j++)
          {
               if (a[i] > a[j])
               {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
               }
          }
     }

     binPacking(n, a, size);

     return 0;
}