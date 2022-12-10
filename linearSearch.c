#include <stdio.h>

int count = 0;

void linearSearch(int n, int a[], int s)
{

      for (int i = 0; i < n; i++)
      {
            if (a[i] == s)
            {
                  count++;
            }
      }
}

int main()
{
      int n, search_element;

      printf("Enter array size: ");
      scanf("%d", &n);

      int a[n];

      for (int i = 0; i < n; i++)
      {
            scanf("%d", &a[i]);
      }

      printf("Enter search value: ");
      scanf("%d", &search_element);

      linearSearch(n, a, search_element);

      if (count == 0)
      {
            printf("value not found\n");
      }
      else
      {
            printf("value founded\n");
      }
}