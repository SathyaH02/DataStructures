#include <stdio.h>
#define MAX 20

int graph[MAX][MAX],visited[MAX],n;

void DFS(int v)
{
    visited[v]=1;
    printf("%d ",v);
    for (int i=0;i<n;i++)
    {
        if (graph[v][i]==1 && !visited[i])
            DFS(i);
    }
}

int main()
{
    int start;
    printf("Enter the no.of vertices: ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    for (int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    printf("Enter the starting vertex: ");
    scanf("%d",&start);
    printf("DFS Traversal: ");
    DFS(start);
    return 0;
}
