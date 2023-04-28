#include<stdio.h>

int main()
{
   int small,i,j,k,temp,a[30],n;
   printf("Enter Array Size: \n");
   scanf("%d",&n);
   printf("Enter elements one by one \n");
   for(i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
   }
   printf("Unsorted array is:\n");
   for(i=0;i<n;i++)
   {
       printf("%d\t",a[i]);
   }

   for(i=0;i<n;i++)
   {
       small=i;
       for(j=i+1;j<n;j++)
       {
           if(a[j]<a[small])
            small=j;
       }

       temp=a[i];
       a[i]=a[small];
       a[small]=temp;

       printf("\nSorted Array after %d pass: \n",i+1);
       for(k=0;k<n;k++)
       {
        printf("%d\t",a[k]);
       }

   }

}