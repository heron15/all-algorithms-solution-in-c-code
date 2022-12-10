#include <stdio.h>
#define size 20

int a[size][size], queue[size], visited[size],
    front = 0, rear = 0, n;

void bfs(int start_vertex)
{

      for (int i = 0; i < n; i++)
      {
            if (a[start_vertex][i] && !visited[i])
            {
                  rear++;
                  queue[rear] = i;
            }
      }

      if (rear >= front)
      {
            visited[queue[front]] = 1;
            bfs(queue[front++]);
      }
}

int main()
{
      printf("Enter number of vertex: ");
      scanf("%d", &n);

      for (int i = 0; i < n; i++)
      {
            queue[i] = 0;
            visited[i] = 0;
      }

      printf("Enter graph data in matrix:\n");

      for (int i = 0; i < n; i++)
      {
            for (int j = 0; j < n; j++)
            {
                  scanf("%d", &a[i][j]);
            }
      }

      int start_vertex;

      printf("Enter starting vertex: ");
      scanf("%d", &start_vertex);

      bfs(start_vertex);

      printf("Reachable node is:\n");

      for (int i = 0; i < n; i++)
      {
            if (visited[i])
            {
                  printf("%d\n", i);
            }
            else
            {
                  printf("Not possible");
            }
      }

      return 0;
}