#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = 0;
int count = 0, i = 0, pos;

void insertatbeg() {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
    count++;
}

void insertatend() {
    if (head == NULL) {
        insertatbeg();
    }
    else {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        struct node* temp = head;
        while (temp->next != 0) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL; // Set the next pointer of the new node to NULL
        count++;
    }
}

void insertatmid() {
    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos > count) {
        printf("Invalid position\n");
    }
    else if (pos == 1) {
        insertatbeg();
    }
    else {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        struct node* temp = head;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        count++;
    }
}

void deleteatbeg() {
    if (head == NULL) {
        printf("Empty\n");
    }
    else {
        struct node* temp = head;
        head = head->next;
        temp->next = NULL; // Set the next pointer of the deleted node to NULL
        free(temp);
        count--;
    }
}

void deleteatend() {
    if (head == NULL) {
        printf("Empty\n");
    }
    else {
        struct node* temp = head, * prevnode;
        while (temp->next != 0) {
            prevnode = temp;
            temp = temp->next;
        }
        if (head == temp) {
            head = NULL;
        }
        else {
            prevnode->next = NULL; // Set the next pointer of the previous node to NULL
        }
        free(temp);
        count--;
    }
}

void deleteatmid() {
    if (pos > count) {
        printf("Invalid position\n");
    }
    else if (pos == 1) {
        deleteatbeg();
    }
    else {
        struct node* temp = head, * nextnode;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        nextnode = temp->next;
        temp->next = nextnode->next;
        nextnode->next = NULL; // Set the next pointer of the deleted node to NULL
        free(nextnode);
        count--;
    }
}

void display() {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nLinked List Operations\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at specified location\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from specified location\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertatbeg();
                break;
            case 2:
                insertatend();
                break;
            case 3:
                insertatmid();
                break;
            case 4:
                deleteatbeg();
                break;
            case 5:
                deleteatend();
                break;
            case 6:
                deleteatmid();
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
