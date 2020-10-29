#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int m;
    printf("\nEnter the number of resources: ");
    scanf("%d",&m);
    int et[n];//={1,2,3,4};
    int r[m];//={1,5};
    printf("\n Enter the execution time of processes: ");
    for(int i=0;i<n;i++)
        scanf("%d",&et[i]);
    printf("\nEnter the ready time of processes: ");
    for(int j=0;j<m;j++)
        scanf("%d",&r[j]);
   // int n=sizeof(et)/sizeof(et[0]);
   // int m=sizeof(r)/sizeof(r[0]);
    int ct[n][m];
    //Phase 1
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            ct[i][j]=et[i]+r[j];
    }
    // Phase 2:
   do
   {
       int maximum=-100;
       int index_i;
       int index_j;
       int minimum=100;
       int min_res;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               ct[i][j]=et[i]+r[j];
               if(ct[i][j]>maximum)
               {
                   maximum=ct[i][j];
                   index_i=i;
                   index_j=j;
               }
              // if(ct[index_i][j]<minimum)
              // {
               //    minimum=ct[index_i][j];
                //   min_res=j;
              // }

              // printf("%d ",ct[i][j]);
           }
           //printf("\n");
       }
        for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(ct[index_i][j]<minimum)
               {
                   minimum=ct[index_i][j];
                   min_res=j;
               }
           }
       }
        r[min_res]=minimum;
      //  printf("%d\n",minimum);
       int position=index_i;
       for(int i=position;i<n-1;i++)
            et[i]=et[i+1];
        //printf("\n The executing time of updated processes is: ");
        for(int i=0;i<n;i++)
        {
            printf("%d ",et[i]);
            printf("\n");
        }
      //  n--;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                printf("%d ",ct[i][j]);
            printf("\n");
        }
        n--;
   }while(n>0);
   return 0;
}

