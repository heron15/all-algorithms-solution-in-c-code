#include <stdio.h>

int knapsack(int n, float profit[], float weight[], float cap)
{

      float x[n], tp = 0.0;
      int i, j, curnt_cap;

      curnt_cap = cap;

      for (int i = 0; i < n; i++)
      {
            x[i] = 0;
      }

      for (int i = 0; i < n; i++)
      {
            if (weight[i] > curnt_cap)
            {
                  break;
            }
            else
            {
                  x[i] = 1.0;
                  tp = tp + profit[i];
                  curnt_cap = curnt_cap - weight[i];
            }
      }

      if(i<n){
            x[i] = curnt_cap / weight[i];
            tp = tp + (x[i] * profit[i]);
      }

      printf("%.2f\n", tp);
}

int main()
{
      float cap, temp;

      int n;

      printf("Enter capacity: ");
      scanf("%f", &cap);

      printf("Enter number of item: ");
      scanf("%d", &n);

      float weight[n], profit[n];
      float ratio[n];  

      for (int i = 0; i < n; i++)
      {
            scanf("%f %f", &weight[i], &profit[i]);
      }

      for (int i = 0; i < n; i++)
      {
            ratio[i] = profit[i] / weight[i];
      }

      for (int i = 0; i < n; i++)
      {
            for (int j = i + 1; j < n; j++)
            {
                  if (ratio[i] < ratio[j])
                  {
                        temp = ratio[i];
                        ratio[i] = ratio[j];
                        ratio[j] = temp;

                        temp = weight[i];
                        weight[i] = weight[j];
                        weight[j] = temp;

                        temp = profit[i];
                        profit[i] = profit[j];
                        profit[j] = temp;
                  }
            }
      }

      knapsack(n, profit, weight, cap);

      return 0;
}