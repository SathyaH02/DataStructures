#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

void createList(int n)
{
    if (n <= 0) {
        printf("n should be greater than 0\n");
        return;
    }

    int data;
    struct node *newNode;

    for (int i = 1; i <= n; i++) {
        newNode = (struct node *)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &data);

        newNode->data = data;
        newNode->prev = newNode->next = NULL;

        if (head == NULL)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    printf("Created linked list of size %d\n", n);
}

void insertAtBegin(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head == NULL)
        head = tail = newNode;
    else {
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtEnd(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = tail;

    if (head == NULL)
        head = tail = newNode;
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtPosition(int data, int pos)
{
    if (pos <= 1) {
        insertAtBegin(data);
        return;
    }

    struct node *temp = head;
    int count = 1;

    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL || temp->next == NULL) {
        insertAtEnd(data);
        return;
    }

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteAtFront()
{
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;

    free(temp);
}

void deleteAtEnd()
{
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = tail;
    tail = tail->prev;

    if (tail != NULL)
        tail->next = NULL;
    else
        head = NULL;

    free(temp);
}

void deleteByValue(int value)
{
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    if (temp == head) {
        deleteAtFront();
        return;
    }

    if (temp == tail) {
        deleteAtEnd();
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);
}

void display()
{
    struct node *temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int ch;

    printf("Menu:\n1. Create list\n2. Insert at position\n3. Delete value\n4. Display\n0. Exit\n");

    do {
        printf("Your choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            int n;
            printf("Enter number of nodes: ");
            scanf("%d", &n);
            createList(n);
        }
        else if (ch == 2) {
            int x, p;
            printf("Enter data and position: ");
            scanf("%d %d", &x, &p);
            insertAtPosition(x, p);
        }
        else if (ch == 3) {
            int x;
            printf("Enter the value to delete: ");
            scanf("%d", &x);
            deleteByValue(x);
        }
        else if (ch == 4) {
            display();
        }
        else if (ch == 0) {
            printf("Exiting...\n");
        }
        else {
            printf("Invalid choice\n");
        }

    } while (ch != 0);

    return 0;
}
