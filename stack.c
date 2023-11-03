#include <stdio.h>
int main() {
int choice, exit = 1, n, stack[100], i, top = -1;
int val;
printf("Enter the number of elements in the array: ");
scanf("%d", &n);
while (exit == 1) {
printf("\nStack Operations:\n");
printf("1. Push\n");
printf("2. Pop\n");
printf("3. Show\n");
printf("4. Exit\n");
printf("Enter the operation to be performed: ");
scanf("%d", &choice);
switch (choice) {
case 1:
if (top == n - 1)
printf("Overflow\n");
else {
printf("Enter the value: ");
scanf("%d", &val);
top = top + 1;
stack[top] = val;
}
break;
case 2:
if (top == -1)
printf("Underflow\n");
else {
printf("Popped element: %d\n", stack[top]);
top = top - 1;
}
break;
case 3:
if (top == -1) {
printf("Stack is Empty\n");
} else {
for (i = top; i >= 0; --i) {
printf("%d\n", stack[i]);
}
}
break;
case 4:
exit = 0;
break;
default:
printf("Invalid sub-choice.\n");
break;
}
}
return 0;
}
