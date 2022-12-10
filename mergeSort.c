#include <stdio.h>

int b[100];

void merge(int a[], int lb, int mid, int up)
{

      int i = lb, j = mid + 1, k = up;

      while (i <= mid && j <= up)
      {
            if (a[i] <= a[j])
            {
                  b[k] = a[i];
                  i++;
            }
            else
            {
                  b[k] = a[j];
                  j++;
            }

            k++;
      }

      if (i > mid)
      {
            while (j <= up)
            {
                  b[k] = a[j];
                  j++;
            }
      }
      else
      {
            while (i <= mid)
            {
                  b[k] = a[i];
                  i++;
                  k++;
            }
      }
}

void mergeSort(int a[], int lb, int up)
{
      if (lb < up)
      {
            int mid = (lb + up) / 2;
            mergeSort(a, lb, mid);
            mergeSort(a, mid + 1, up);
            merge(a, lb, mid, up);
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

      mergeSort(a, 0, n - 1);

      for (int i = 0; i < n; i++)
      {
            printf("%d ", b[i]);
      }

      return 0;
}