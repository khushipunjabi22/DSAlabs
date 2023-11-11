#include <stdio.h>
int main()
{
int choice, sub, n,exit=1;
int i,j,k,minIndex,temp;
do
{
printf("1. Insertion Sort\n");
printf("2. Selection Sort\n");
printf("3. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice)
{
case 1: {
while(exit==1){
printf("For Insertion Sort\n");
printf("1. Enter array\n");
printf("2. Display array\n");
printf("3. Apply insertion Sort\n");
printf("4. Exit\n");
printf("Enter your sub-choice: ");
scanf("%d", &sub);
switch (sub)
{
case 1:
printf("Enter the number of elements in the array: ");
scanf("%d", &n);
int a[100];
for (int i = 0; i < n; i++) {
printf("Enter element: ");
scanf("%d", &a[i]);
}
break;
case 2: printf("[\t");
for (int i = 0; i < n; i++) {
printf("%d\t", a[i]);
}
printf("]\n");
break;
case 3:
for (i = 1; i<n; i++) {
temp=a[i];
printf("Pass %d:\t", i);
for(j=i-1;j>=0;j--){
if(a[j]>temp)
{
a[j+1]=a[j];
}
else
break;
}
a[j+1]=temp;
for (int k = 0; k < n; k++) {
printf("%d\t", a[k]);
}
printf("\n");
}
printf("Sorted Array: \n[\t");
for ( i = 0; i<n ;i++) {
printf("%d\t", a[i]);
}
printf("]\n");
break;
case 4:
exit=0;
break;
default:
printf("Invalid sub-choice.\n");
break;
}
}
break;}
case 2: {
while(exit==0){
printf("For Selection Sort\n");
printf("1. Enter array\n");
printf("2. Display array\n");
printf("3. Apply selection Sort\n");
printf("4. Exit\n");
printf("Enter your sub-choice: ");
scanf("%d", &sub);
switch (sub)
{
case 1:
printf("Enter the number of elements in the array: ");
scanf("%d", &n);
int a[100];
for (int i = 0; i < n; i++) {
printf("Enter element: ");
scanf("%d", &a[i]);
}
break;
case 2: printf("[\t");
for (int i = 0; i < n; i++) {
printf("%d\t", a[i]);
}
printf("]\n");
break;
case 3:
for (i = 0; i< n-1; i++) {
int minIndex = i;
for (j = i+1; j<n; j++) {
if (a[j] < a[minIndex]) {
minIndex=j;
}
}
temp = a[minIndex];
a[minIndex] = a[i];
a[i] = temp;
printf("Pass %d:\t", i + 1);
for (int k = 0; k < n; k++) {
printf("%d ", a[k]);
}
printf("\n");
}
printf("Sorted Array: \n[\t");
for (i = 0; i<n;i++) {
printf("%d\t", a[i]);
}
printf("]\n");
break;
case 4:
exit=1;
break;
default:
printf("Invalid sub-choice.\n");
break;
}
}
break;}
case 3 :
break;
default:
printf("Invalid choice.\n");
break;
}
}
while (choice != 3);
return 0;
}
