#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int newdata) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = newdata;
    newnode->next = NULL;
    return newnode;
}

struct Node* insertBeforeKey(struct Node* head, int newdata, int key) {
    if(head == NULL)
        return NULL;

    if(head->data == key) {
        struct Node* newnode = createNode(newdata);
        newnode->next = head;
        return newnode;
    }

    struct Node* curr = head;
    struct Node* prev = NULL;

    while(curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if(curr != NULL) {
        struct Node* newnode = createNode(newdata);
        prev->next = newnode;
        newnode->next = curr;
    }

    return head;
}
void printList(struct Node* head) {
    struct Node* curr = head;
    while(curr != NULL) {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    int newdata = 6;
    int key = 2;

    head = insertBeforeKey(head, newdata, key);

    printList(head);

    return 0;
}