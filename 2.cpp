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

struct Node* insertAfterkey(struct Node* head, int newdata, int key) {
    struct Node* curr = head;
    while(curr != NULL) {
        if (curr->data == key) 
            break;
        curr = curr->next;
    }

    if(curr == NULL) 
        return head;
    
    struct Node* newnode = createNode(newdata);
    newnode->next = curr->next;
    curr->next = newnode;
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
    struct Node* head = createNode(2);
    head->next = createNode(3);
    head->next->next = createNode(4);
    head->next->next->next = createNode(5);
    head->next->next->next->next = createNode(6);
    head->next->next->next->next->next = createNode(7);

    int newdata = 12;
    int key = 4;
    head = insertAfterkey(head, newdata, key);
    printList(head);

    return 0;
}