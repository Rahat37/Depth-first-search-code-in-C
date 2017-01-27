/*

    Program:Depth first search(DFS)
    Author: Saad Ahmad Rahat
*/
#include<stdio.h>
#include<conio.h>
int adj[10][10],n,i,j,p[10],time,d[10],v[10],f[10],l;
char color[10];

void graph()
{
    for(i=1;i<=n;i++)
    {
        color[i] = 'w';
        p[i] = -1;
    }
    time = 0;
    for(j=1;j<=n;j++)
    {
        if(color[j]=='w')
        {
            dfs_visit(j);
        }
    }
}

void dfs_visit(int j)
{
    time = time + 1;
    d[j] = time;
    color[j] = 'G';
    for(l=1;l<=n;l++)
    {
        if(color[l]=='w' && adj[j][l]==1)
        {
            v[l]=j;
            dfs_visit(l);
        }
    }
    color[j]='B';
    time = time + 1;
    f[j] = time;
}

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            scanf("%d",&adj[i][j]);
    }
    graph();
    for(j=1;j<=n;j++)
    {
        printf("%d start time=%d End time=%d\n",j,d[j],f[j]);
    }
    return 0;
}
