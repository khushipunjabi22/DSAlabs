#include<stdio.h>
int main()
{
int choice,exit=1,n,queue[100],i,front=-1,rear=-1;
int val;
printf("Enter the number of elements in the array: ");
scanf("%d", &n);
while(exit==1){
printf("\nQueue Operations:\n");
printf("1. Insert\n");
printf("2. Delete\n");
printf("3. Display\n");
printf("4. Exit\n");
printf("Enter the operation to be performed: ");
scanf("%d", &choice);
switch (choice)
{
case 1:
if(rear+1 == n)
printf("\nOverflow\n");
else if (front == -1 && rear== -1)
{
front=rear=0;
printf("Enter the value: ");
scanf("%d",&val);
queue[rear]=val;
}
else
{
rear++;
printf("Enter the value: ");
scanf("%d",&val);
queue[rear]=val;
}
break;
case 2:
if (front == -1 || front>rear)
printf("Underflow\n");
else
{
printf("The element deleted is %d\n",queue[front]);
if (front== rear)
front = rear = -1;
else
front++;
}
break;
case 3:
if (front == -1 && rear == -1)
printf("Queue is empty\n");
else{
for(i=front;i<rear+1;i++)
{
printf("%d\n",queue[i]);
}
}
break;
case 4:
exit=0;
break;
default:
printf("Invalid sub-choice.\n");
break;
}
}
}
