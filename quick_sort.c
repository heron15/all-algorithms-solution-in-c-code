#include <stdio.h>

int swap(int *a, int *b)
{
      int temp = *a;
      *a = *b;
      *b = temp;
}

int prtition(int a[], int left, int right)
{
      int pivot = a[left];

      while (left != right)
      {
            if (pivot == a[left])
            {
                  if (a[right] > pivot)
                  {
                        right--;
                  }
                  else if (a[right] <= pivot)
                  {
                        swap(&a[left], &a[right]);
                        pivot = a[right];
                        left--;
                  }
            }
            else if (pivot == a[right])
            {
                  if (a[left] < pivot)
                  {
                        left++;
                  }
                  else if (a[left] >= pivot)
                  {
                        swap(&a[left], &a[right]);
                        pivot = a[left];
                        right--;
                  }
            }
      }

      return left;
}

void quickSort(int a[], int left, int right)
{
      if (left < right)
      {
            int pivot = prtition(a, left, right);
            quickSort(a, left, pivot - 1);
            quickSort(a, pivot + 1, right);
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

      quickSort(a, 0, n - 1);

      for (int i = 0; i < n; i++)
      {
            printf("%d ", a[i]);
      }

      return 0;
}