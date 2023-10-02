#include<stdio.h>
#include <stdlib.h>

void bsort(int a[],int n)
{
 int step,temp,i;
 for(step=0;step<n-1;step++)
 {
   for(i=0;i<n-step-1;i++)
   {
     if(a[i]>a[i+1])
     {
       temp=a[i];
       a[i]=a[i+1];
       a[i+1]=temp;
     }
   }
 }
 printf("sorted array is");
 for(i=0;i<n;i++)
 {
 printf("%d ",a[i]);
 }
 }
void ssort(int a[],int n)
 
 {
   int i,j,min,t;
   for (i = 0; i < n - 1; i++)
   {
     min= i;
      for (j = i + 1; j < n; j++)
       {
   if (a[j] < a[min])
    min= j;
}
   if (min != i)
{
  t=a[i];
  a[i]=a[min];
  a[min]=t;
         }
  }
 printf("sorted array is");
 for(i=0;i<n;i++)
 {
 printf("%d ",a[i]);
 }
 }
 void isort(int a[],int n)
 {
   int i,j,min;
   for(i=1;i<n;i++)
   {
     min=a[i];
     j=i-1;
     while(min<a[j] && j >= 0)
     {
       a[j+1]=a[j];
       j=j-1;
      }
      a[j+1]=min;
    }
    printf("sorted array is");
 for(i=0;i<n;i++)
 {
 printf("%d ",a[i]);
 }
 
   }
   
 int main()
 {
  int a[100],n,i,ch;
  printf("enter the limit of the array\n");
  scanf("%d",&n);
  printf("enter the elements of the array\n");
  for(i=0;i<n;i++)
  {
     scanf("%d",&a[i]);
  }
  do
  {
  printf("\n1.bubble sort\n2.selection sort\n3.insertion sort\n4.exit");
  printf("\nenter your choice:\n");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1:bsort(a,n);
           break;
   case 2:ssort(a,n);
          break;
    case 3:isort(a,n);
          break;
   case 4:
         exit(0);
           
    default:printf("invalid entry");
            break;
   }
   }
   while(ch!=4);
   return 0;
  }

