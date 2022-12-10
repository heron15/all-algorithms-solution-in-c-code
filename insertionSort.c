#include <stdio.h>

void insertionSort(int a[], int n)
{
      for (int i = 1; i < n; i++)
      {
            int temp = a[i];
            int j = i - 1;

            while (j >= 0 && a[j] > temp)
            {
                  a[j + 1] = a[j];
                  j--;
            }

            a[j + 1] = temp;
      }

      for (int i = n - 1; i >= 0; i--)
      {
            printf("%d ", a[i]);
      }
}

int main()
{

      int n;
      scanf("%d", &n);

      int a[n];

      for (int i = 0; i < n; i++)
      {
            scanf("%d", &a[i]);
      }

      insertionSort(a, n);

      return 0;
}