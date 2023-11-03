#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (front == 0 && rear == 0) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
     struct Node* temp = front;
     if (front == 0 && rear == 0) {
        printf("Queue is empty. Cannot dequeue.\n");
    }
    else {
        printf("The dequed element is %d", front -> data);
        front = front->next;
    free(temp);
    }
}

void display() {
    struct Node* temp;
    if (front == 0 && rear == 0) {
        printf("Queue is empty.\n");
    }
    else {
       temp = front;
       while (temp!=0)
       {
        printf("\t%d",temp->data);
        temp=temp->next;
       }

    }
}

int main() {
    int choice, data;

    while (1) {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
