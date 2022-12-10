#include <stdio.h>

int count = 0;

void binarySearch(int n, int a[], int s)
{

      int left = 0;
      int right = n - 1;
      int mid = (left + right) / 2;

      for (int i = 0; i < n; i++)
      {
            if (s == a[mid])
            {
                  count++;
                  break;
            }

            if (s > a[mid])
            {
                  left = mid + 1;
                  mid = (left + right) / 2;
            }

            if (s < a[mid])
            {
                  right = mid - 1;
                  mid = (left + mid) / 2;
            }
      }
}

int main()
{

      int n, s;
      scanf("%d", &n);

      int a[n];

      for (int i = 0; i < n; i++)
      {
            scanf("%d", &a[i]);
      }

      scanf("%d", &s);

      binarySearch(n, a, s);

      if (count == 0)
      {
            printf("not founded\n");
      }
      else
      {
            printf("founded\n");
      }
}