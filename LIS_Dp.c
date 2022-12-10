#include <stdio.h>

void lis(int a[], int n)
{
      int length[n], prev[n];

      for (int i = 0; i < n; i++)
      {
            length[i] = 1;
            prev[i] = -1;
      }

      for (int i = 1; i < n; i++)
      {
            for (int j = 0; j < i; j++)
            {

                  if (a[i] > a[j] && length[i] < length[j] + 1)
                  {
                        length[i] = length[j] + 1;
                        prev[i] = j;
                  }
            }
      }

      int max = length[0], index = 0;

      for (int i = 0; i < n; i++)
      {
            if (max < length[i])
            {
                  max = length[i];
                  index += 1;
            }
      }

      printf("Length of LIS: %d\n", max);

      max = length[0];
      int firstPrint = 0;

      for (int i = 0; i < n; i++)
      {
            if (max < length[i])
            {
                  if (!(firstPrint && i))
                  {
                        printf("%d", a[i - 1]);
                        firstPrint = 1;
                  }
                  max = length[i];
                  while (i < n && length[i] == length[i + 1])
                  {
                        i++;
                  }

                  printf(" %d", a[i]);
            }
      }
}

int main()
{

      int n;

      printf("Enter array size: ");
      scanf("%d", &n);

      int a[n];

      printf("Enter array value: ");

      for (int i = 0; i < n; i++)
      {
            scanf("%d", &a[i]);
      }

      lis(a, n);

      return 0;
}