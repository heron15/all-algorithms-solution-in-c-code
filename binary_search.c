#include <stdio.h>

int main()
{
      int n, first, last, mid, search;

      printf("Enter array size: ");
      scanf("%d", &n);

      int a[n];

      for (int i = 0; i < n; i++)
      {
            scanf("%d", &a[i]);
      }

      first = 0;
      last = n - 1;
      mid = (first + last) / 2;

      printf("Enter seacrh element: ");
      scanf("%d", &search);

      while (first <= last)
      {
            if (search == a[mid])
            {
                  printf("founded");
                  break;
            }

            if (search > a[mid])
            {
                  first = mid + 1;
                  mid = (first + last) / 2;
            }
            
            if (search < a[mid])
            {
                  last = mid - 1;
                  mid = (first + last) / 2;
            }
      }
      
      if (first > last)
      {
            printf("Not founded");
      }
}