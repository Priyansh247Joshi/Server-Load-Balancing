#include<stdio.h>
int main()
{
    int n; //Number of tasks
    int m; //Number of resources
    int i,j;
    printf("Enter the number of Tasks: ");
    scanf("%d",&n);
    printf("\nEnter the number of resources: ");
    scanf("%d",&m);
    int et[n],r[m];
    printf("\nEnter the execution time of tasks: ");
    for(i=0;i<n;i++)
        scanf("%d",&et[i]);
    printf("Enter the ready time of resources: ");
    for(j=0;j<m;j++)
        scanf("%d",&r[j]);
    int c[n][m]; //Matrix to store completion time of tasks corresponding to each resources
    
    int min=c[0][0],index_i,min_res,index_j;
    do
    {
        printf("completion time :\n");
        for (i = 0; i < n; i++)
        {

            for (j = 0; j < m; j++)
            {
                c[i][j]=et[i]+r[j];
                printf("%d  ",c[i][j]);
                if (min > c[i][j])
                {
                    min = c[i][j];
                    index_i=i;
                    index_j=min_res=j;

                }

            }
            printf("\n");

        }
        r[min_res]=min;
        for ( i = index_i- 1; i < n - 1; i++)
            et[i] = et[i+1];
        printf("Udated Ready time of resources:\n");
        for (i = 0; i < n - 1; i++)
            printf("%d\n", et[i]);
        n--;

    }while(n>0);
}

