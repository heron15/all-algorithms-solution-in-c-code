#include <stdio.h>

int min(int a, int b)
{
      if (a > b)
      {
            return b;
      }
      else
      {
            return a;
      }
}

void minimumNumberOfCoin(int n, int coin[], int amount)
{
      int solution[n][amount + 1];

      for (int i = 0; i < n; i++)
      {
            solution[i][0] = 0;

            for (int j = 1; j < amount + 1; j++)
            {
                  solution[0][j] = j;
            }
      }

      for (int i = 1; i < n; i++)
      {

            for (int j = 1; j < amount + 1; j++)
            {

                  if (coin[i] > j)
                  {
                        solution[i][j] = solution[i - 1][j];
                  }
                  else
                  {
                        solution[i][j] = min(solution[i - 1][j], 1 + solution[i][j - coin[i]]);
                  }
            }
      }

      for (int i = 0; i < n; i++)
      {
            for (int j = 0; j < amount + 1; j++)
            {
                  printf("%d ", solution[i][j]);
            }
            printf("\n");
      }

      printf("Coin Require: %d\n", solution[n - 1][amount]);

      printf("Requare coin is: ");

      int i = n - 1;
      int j = amount;
      int mini = solution[i][j];

      while (j != 0)
      {
            if (solution[i - 1][j] == mini)
            {
                  i--;
            }
            else
            {
                  printf("%d ", coin[i]);
                  j = j - coin[i];
                  mini = solution[i][j];
            }
      }
}

int main()
{
      int n;
      printf("Enter number of coin: ");
      scanf("%d", &n);

      int coin[n];

      printf("Enter coin:\n");

      for (int i = 0; i < n; i++)
      {
            scanf("%d", &coin[i]);
      }

      int amount;
      printf("Enter amount: ");
      scanf("%d", &amount);

      minimumNumberOfCoin(n, coin, amount);

      return 0;
}