#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *createNode(int data){
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_front(int data){
    struct Node *new_node = createNode(data);
    if (head == NULL){
        head = new_node;
        return;
    }
    new_node->next = head;
    head = new_node;
    return;
}

void insert_end(int data){
    struct Node *new_node = createNode(data);
    if (head == NULL){
        head = new_node;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
    return;
}

// void insert_after(int data, int key){
//     struct Node *new_node = createNode(data);
//     struct Node *temp = head;
//     while (temp != NULL && temp->data != key)
//         temp = temp->next;
//     if (temp == NULL){
//         printf("Key not found\n");
//         return;
//     }
//     new_node->next = temp->next;
//     temp->next = new_node;
//     return;
// }

void insert_after(int data, int key){
    struct Node *new_node = createNode(data);
    struct Node *temp = head;
    while (temp != NULL){
        if (temp->data == key){
            new_node->next = temp->next;
            temp->next = new_node;
            return;
        }
        else{
            temp = temp->next;
        }
    }
    if (temp == NULL){
        printf("Key not found\n");
        return;
    }
}

// void insert_before(int data, int key){
//     struct Node *new_node = createNode(data);
//     struct Node *temp = head;
//     struct Node *ptr = NULL;    
//     while (temp != NULL && temp->data != key){
//         ptr = temp;
//         temp = temp->next;
//     }
//     if (temp == NULL){
//         printf("Key not found\n");
//         return;
//     }
//     new_node->next = temp;
//     ptr->next = new_node;
//     return;
// }

void insert_before(int data, int key){
    struct Node *new_node = createNode(data);
    if (head != NULL && head->data == key) {
        new_node->next = head;
        head = new_node;
        return;
    }
    struct Node *temp = head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->next->data == key) {
            new_node->next = temp->next;
            temp->next = new_node;
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL){
        printf("Key not found\n");
        return;
    }
}

void delete_front(){
    if (head == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return;
}

void delete_end(){
    if (head == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    struct Node *prev = NULL;
    while (temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL)
        head = NULL;
    else
        prev->next = NULL;
    free(temp);
    return;
}

void delete_after(int key){
    if (head == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    struct Node *prev = NULL;
    while (temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL){
        printf("Key not found\n");
        return;
    }
    if (temp->next == NULL){
        printf("No node after key\n");
        return;
    }
    prev = temp;
    temp = temp->next;
    prev->next = temp->next;
    free(temp);
    return;
}

void delete_before(int key) {
    if (head == NULL) {
        printf("List is empty");
        return;
    }

    if (head->data == key) {
        printf("No node before key");
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;
    struct Node *prev_prev = NULL;

    while (temp != NULL && temp->data != key) {
        prev_prev = prev;
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key not found");
        return;
    }

    if (prev == NULL) {
        printf("No node before key\n");
        return;
    }

    if (prev_prev == NULL) {
        head = temp;
        free(prev);
    } else {
        prev_prev->next = temp;
        free(prev);
    }
}

void display(){
    struct Node *temp = head;
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}

int main() {
    int num, key, choice;

    while (1)
    {
        printf("\nLinked List Program : \n");
        printf("0. Exit\n");

        printf("1. Insert Front\n");
        printf("2. Insert End\n");
        printf("3. Insert After\n");
        printf("4. Insert Before\n");

        printf("5. Delete Front\n");
        printf("6. Delete End\n");
        printf("7. Delete After\n");
        printf("8. Delete Before\n");

        printf("9. Display\n");

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
            printf("Enter the key : ");
            scanf("%d", &key);
            delete_after(key);
            break;

        case 8:
            printf("Enter the key : ");
            scanf("%d", &key);
            delete_before(key);
            break;

        case 9:
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
