#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head = NULL;

struct Node *createNode(int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = new_node;
    new_node->prev = new_node;
    return new_node;
}

void insert_front(int data) {
    struct Node *new_node = createNode(data);
    if (head == NULL) {
        head = new_node;
        return;
    }
    struct Node *ptr = head->prev;
    new_node->next = head;
    new_node->prev = ptr;
    ptr->next = new_node;
    head->prev = new_node;
    head = new_node;
}

void insert_end(int data) {
    struct Node *new_node = createNode(data);
    if (head == NULL) {
        head = new_node;
        return;
    }
    struct Node *ptr = head->prev;
    ptr->next = new_node;
    new_node->prev = ptr;
    new_node->next = head;
    head->prev = new_node;
}

void insert_after(int data, int key) {
    if (head == NULL) {
        printf("Key not found\n");
        return;
    }
    struct Node *ptr = head;
    do {
        if (ptr->data == key) {
            struct Node *new_node = createNode(data);
            new_node->next = ptr->next;
            new_node->prev = ptr;
            ptr->next->prev = new_node;
            ptr->next = new_node;
            return;
        }
        ptr = ptr->next;
    } while (ptr != head);
    printf("Key not found\n");
}

void insert_before(int data, int key) {
    if (head == NULL) {
        printf("Key not found\n");
        return;
    }
    struct Node *ptr = head;
    do {
        if (ptr->data == key) {
            struct Node *new_node = createNode(data);
            new_node->next = ptr;
            new_node->prev = ptr->prev;
            ptr->prev->next = new_node;
            ptr->prev = new_node;
            if (ptr == head)
                head = new_node;
            return;
        }
        ptr = ptr->next;
    } while (ptr != head);
    printf("Key not found\n");
}

void delete_front() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *ptr = head;
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    head->prev->next = head->next;
    head->next->prev = head->prev;
    head = head->next;
    free(ptr);
}

void delete_end() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *ptr = head->prev;
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    ptr->prev->next = head;
    head->prev = ptr->prev;
    free(ptr);
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *ptr = head;
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}

int main() {
    int num, key, choice;

    while (1)
    {
        printf("\nDoubley Lisked List Program : \n");
        printf("0. Exit\n");

        printf("1. Insert Front\n");
        printf("2. Insert End\n");
        printf("3. Insert After\n");
        printf("4. Insert Before\n");

        printf("5. Delete Front\n");
        printf("6. Delete End\n");

        printf("7. Display\n");

        printf("Enter your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter a num to insert front : ");
            scanf("%d", &num);
            insert_front(num);
            break;

        case 2:
            printf("Enter a num to insert end : ");
            scanf("%d", &num);
            insert_end(num);
            break;

        case 3:
            printf("Enter a num to insert : ");
            scanf("%d", &num);
            printf("Enter the key : ");
            scanf("%d", &key);
            insert_after(num, key);
            break;

        case 4:
            printf("Enter a num to insert : ");
            scanf("%d", &num);
            printf("Enter the key : ");
            scanf("%d", &key);
            insert_before(num, key);
            break;

        case 5:
            delete_front();
            break;

        case 6:
            delete_end();
            break;

        case 7:
            display();
            break;

        case 0:
            return 0;
        
        default:
            printf("Enter a valid Choice");
            break;
        }
    }
    
    return 0;
}