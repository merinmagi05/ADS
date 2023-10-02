#include <stdio.h>

int a[50], n, choice, i, x, j;
int main()
{
 printf("Enter the size of array: ");
 scanf("%d", &n);
 printf("Enter the elements:\n");
 for (i = 0; i < n; i++)
 {
 scanf("%d", &a[i]);
 }
 while (choice != 6)
 {
 printf("\nChoose from the following \n1.Insert \n2.Delete \n3.Sort \n4.Merge \n5.Display \n6.Exit ");
 printf("\nEnter your choice:");
 scanf("%d", &choice);
 switch (choice)
 {
 case 1:
 {
 insert();
 break;
 }
 case 2:
 {
 delete();
 break;
 }
 case 3:
 {
 sort();
 break;
 }
 case 4:
 {
 merge();
 break;
 }
 case 5:
 {
 display();
 break;
 }
 case 6:
 {
 printf("\nExit\n");
 break;
 }
 default:
 {
 printf("Enter the invalid option");
 }
 }
 }
 return 0;
}








void insert()
{
 int pos;
 printf("Enter the position :");
 scanf("%d", &pos);
 if (pos < 0 || pos > n)
 {
 printf("Invalid position");
 return;
 }
 else
 {
 printf("Enter the element to insert: ");
 scanf("%d", &x);
 for (i = n; i > pos; i--)
 {
 a[i] = a[i - 1];
 }
 a[pos] = x;
 n++;
 printf("The array after insertion:");
 for(i=0;i<n;i++)
 {
 printf(" %d ",a[i]);
 }
 }
}
void delete()
{
 int pos;
 printf("Enter the position of element to delete: ");
 scanf("%d", &pos);
 if (pos < 0 || pos > n)
 {
 printf("Ivalid position");
 return;
 }
 else
 {
 if (pos >= n + 1)
 {
 printf("Deletion is not possible");
 }
 else
 {
 for (i = pos; i < n - 1; i++)
 {
 a[i] = a[i + 1];
 }
 n--;
 printf("The array elements after deletion are:");
for(i=0;i<n;i++)
{
printf(" %d ",a[i]);
}
 }
 }
}
void display()
{
 printf("Array Elements:\n");
 for (i = 0; i < n; i++)
 {
 printf(" %d ", a[i]);
 }
}
void sort()
{
 int temp;
 printf("Sorted array:\n");
 for (i = 0; i < n - 1; i++)
 {
 for (j = 0; j < n - i - 1; j++)
 {
 if (a[j] > a[j + 1])
 {
 temp = a[j];
 a[j] = a[j + 1];
 a[j + 1] = temp;
 }
 }
 }
 for(int i = 0; i < n ; i++)       
        printf(" %d ",a[i]);
}
void merge()
{
 int n2, n3, b[50], c[50];
 printf("Enter the size of second array: ");
 scanf("%d", &n2);
 printf("Enter the array of second elements:\n");
 for (i = 0; i < n2; i++)
 {
 scanf("%d", &b[i]);
 }
 n3 = n + n2;
 for (i = 0; i < n; i++)
 {
 c[i] = a[i];
 }
 for (i = 0; i < n2; i++)
 {
 c[i + n] = b[i];
 }
 n=n3;
 for(i = 0; i< n3; i++){
 a[i] = c[i];
 }
 printf("The merged array: ");
 for (i = 0; i < n3; i++)
 {
 printf("%d ", a[i]);
 }
}
