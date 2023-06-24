#include<stdio.h>
#include<stdlib.h>

struct node {
    int item;
    struct node* next;
};

void insertAtLast(struct node** s, int data) {
    struct node* n, * t;
    n = (struct node*)malloc(sizeof(struct node));
    n->item = data;
    n->next = NULL;
    if (*s == NULL)
        *s = n;
    else {
        t = *s;
        while (t->next != NULL)
            t = t->next;
        t->next = n;
    }
}

void insertAtBeginning(struct node** s, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->item = data;
    newNode->next = NULL;

    if (*s == NULL) {
        *s = newNode;
    } else {
        newNode->next = *s;
        *s = newNode;
    }
}

void deleteFirst(struct node** s) {
    if (*s != NULL) {
        struct node* t = *s;
        *s = t->next;
        free(t);
    }
}

void deleteNode(struct node** s, int data) {
    struct node* current = *s;
    struct node* previous = NULL;

    while (current != NULL) {
        if (current->item == data) {
            if (previous == NULL) {
                *s = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void insertAfter(struct node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->item = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void viewList(struct node* start) {
    while (start) {
        printf("%d ", start->item);
        start = start->next;
    }
    printf("\n");
}

int main() {
    struct node* start = NULL;
    insertAtLast(&start, 25);
    insertAtLast(&start, 26);
    insertAtLast(&start, 27);
    insertAtLast(&start, 28);
    insertAtBeginning(&start, 1); 
    printf("Original List: ");
    viewList(start);

    deleteFirst(&start);
    printf("List after deleting the first node: ");
    viewList(start);

    deleteNode(&start, 27);
    printf("List after deleting node with value 27: ");
    viewList(start);

    insertAfter(start, 30);
    printf("List after inserting 30 after the first node: ");
    viewList(start);

    return 0;
}

