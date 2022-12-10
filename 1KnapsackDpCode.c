#include <stdio.h>

int max(int a, int b)
{
      if (a > b)
      {
            return a;
      }
      else
      {
            return b;
      }
}

void maxProfit(int w[], int p[], int n, int c)
{
      int solution[n + 1][c + 1];

      for (int i = 0; i <= n; i++)
      {
            for (int j = 0; j <= c; j++)
            {

                  if (i == 0 || j == 0)
                  {
                        solution[i][j] = 0;
                  }
                  else if (w[i] <= j)
                  {
                        solution[i][j] =
                            max(solution[i - 1][j], p[i] + solution[i - 1][j - w[i]]);
                  }
                  else
                  {
                        solution[i][j] = solution[i - 1][j];
                  }
            }
      }

      printf("\nSolution Tableis:");

      for (int i = 0; i < n; i++)
      {
            for (int j = 0; j <= c; j++)
            {
                  printf("%d ", solution[i][j]);
            }
            printf("\n");
      }

      printf("\nMax Profit is: %d\n", solution[n - 1][c]);

      int i = n - 1;
      int j = c;
      int wet = solution[i][j];

      printf("Requare weight: ");

      while (j != 0)
      {
            if (solution[i - 1][j] == wet)
            {
                  i--;
            }
            else
            {
                  printf("%d ", w[i]);
                  j = j - w[i];
                  wet = solution[i][j];
            }
      }
}

int main()
{
      int n, c;

      printf("Enter number of item: ");
      scanf("%d", &n);

      int weight[n], profit[n];

      printf("Enter weight: ");

      for (int i = 0; i < n; i++)
      {
            scanf("%d", &weight[i]);
      }

      printf("Enter profit: ");

      for (int i = 0; i < n; i++)
      {
            scanf("%d", &profit[i]);
      }

      printf("Enter capacity: ");
      scanf("%d", &c);

      maxProfit(weight, profit, n, c);

      return 0;
}