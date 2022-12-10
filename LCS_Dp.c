#include <stdio.h>
#include <string.h>

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

void lcs(char xAry[], char yAry[], int x, int y)
{

      int solution[x + 1][y + 1];
      char lcsValue[100];

      for (int i = 0; i <= x; i++)
      {
            solution[i][0] = 0;
      }

      for (int j = 0; j <= y; j++)
      {
            solution[0][j] = 0;
      }

      for (int i = 1; i <= x; i++)
      {
            for (int j = 1; j <= y; j++)
            {

                  if (xAry[i - 1] == yAry[j - 1])
                  {
                        solution[i][j] = solution[i - 1][j - 1] + 1;
                  }
                  else
                  {
                        solution[i][j] = max(solution[i][j - 1], solution[i - 1][j]);
                  }
            }
      }

      for (int i = 0; i <= x; i++)
      {
            for (int j = 0; j <= y; j++)
            {
                  printf("%d ", solution[i][j]);
            }

            printf("\n");
      }

      printf("LCS lenght is: %d", solution[x][y]);
}

int main()
{

      char xAry[] = "PRESIDENT";
      char yAry[] = "PROVIDENCE";

      int x = strlen(xAry);
      int y = strlen(yAry);

      lcs(xAry, yAry, x, y);

      return 0;
}