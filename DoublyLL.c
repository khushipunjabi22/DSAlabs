#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;
struct Node* tail = NULL;

void createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    if (tail == NULL) {
        tail = newNode;
    }
}

void insertAtEnd(int data) {
    createNode(data);
}

void insertAtPosition(int data, int position) {
    if (position == 1) {
        insertAtBeginning(data);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node* current = head;
    int i;
    for (i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;

    if (newNode->next == NULL) {
        tail = newNode;
    }
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else {
        struct Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }
        free(temp);
    }
}

void deleteFromEnd() {
    if (tail == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else {
        struct Node* temp = tail;
        tail = tail->prev;
        if (tail != NULL) {
            tail->next = NULL;
        } else {
            head = NULL;
        }
        free(temp);
    }
}

void deleteFromPosition(int position) {
    if (position == 1) {
        deleteFromBeginning();
        return;
    }

    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* current = head;
    int i;
    for (i = 1; i < position && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position\n");
        return;
    }

    if (current->next != NULL) {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    } else {
        current->prev->next = NULL;
        tail = current->prev;
    }

    free(current);
}

void display() {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data, position;

    while (1) {
        printf("\nDoubly Linked List Operations\n");
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
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(data, position);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(position);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
