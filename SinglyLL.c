#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
int pos, i = 1, count = 0;

void create() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
}

void insertatbeg() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
    count++;
}

void insertatend() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    count++;
}

void insertinmid() {
    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos > count) {
        printf("Invalid position\n");
    } else {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        struct node *temp = head;
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
        printf("List is empty. Nothing to delete.\n");
    } else {
        struct node *temp = head;
        head = head->next;
        free(temp);
        count--;
    }
}

void deleteatend() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
        count--;
    } else {
        struct node *temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
        count--;
    }
}

void deleteinmid() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else {
        printf("Enter position: ");
        scanf("%d", &pos);
        if (pos > count || pos < 1) {
            printf("Invalid position\n");
        } else if (pos == 1) {
            deleteatbeg();
        } else if (pos == count) {
            deleteatend();
        } else {
            struct node *temp = head;
            for (i = 1; i < pos - 1; i++) {
                temp = temp->next;
            }
            struct node *temp2 = temp->next;
            temp->next = temp2->next;
            free(temp2);
            count--;
        }
    }
}

void display() {
    struct node *temp = head;
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
                insertinmid();
                break;
            case 4:
                deleteatbeg();
                break;
            case 5:
                deleteatend();
                break;
            case 6:
                deleteinmid();
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
