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

struct Node* deleteLast(struct Node* head) {
    struct Node* last = head;
    struct Node* prev = NULL; 
    
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    while (last->next != NULL) {
        prev = last;
        last = last->next;
    }
    free(last);
    prev->next = NULL;

    return head;
}

void printList(struct Node* head) {
    struct Node* curr = head;
    while (curr != NULL) {
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

    printList(head);
    head = deleteLast(head);
    printList(head);


    return 0;
}